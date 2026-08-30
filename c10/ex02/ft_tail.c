#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>

#define HEADER_FORMAT "==> %s <==\n"
#define BUFFER_SIZE 1024

void	ft_putstr_fd(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	ft_putnbr_fd(int fd, int n)
{
	char	c;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(fd, n / 10);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	print_error(char *prog, char *filename, char *msg)
{
	ft_putstr_fd(2, basename(prog));
	ft_putstr_fd(2, ": ");
	if (filename)
	{
		ft_putstr_fd(2, filename);
		ft_putstr_fd(2, ": ");
	}
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, "\n");
}

char	*read_entire_file(int fd, int *file_size)
{
	char	*buf;
	char	tmp[BUFFER_SIZE];
	int		bytes;
	int		total;

	total = 0;
	buf = NULL;
	while ((bytes = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		buf = realloc(buf, total + bytes);
		if (!buf)
		{
			*file_size = -1;
			return (NULL);
		}
		int	i;
		i = 0;
		while (i < bytes)
		{
			buf[total + i] = tmp[i];
			i++;
		}
		total += bytes;
	}
	*file_size = total;
	return (buf);
}

void	print_tail(char *prog, char *filename, int nbytes, int multiple_files)
{
	int		fd;
	char	*content;
	int		file_size;
	int		start;

	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
		{
			print_error(prog, filename, strerror(errno));
			return ;
		}
	}
	else
		fd = 0;

	content = read_entire_file(fd, &file_size);
	if (fd != 0)
		close(fd);
	if (!content && file_size < 0)
	{
		print_error(prog, filename, "memory error");
		return ;
	}
	if (multiple_files && filename)
	{
		ft_putstr_fd(1, "==> ");
		ft_putstr_fd(1, filename);
		ft_putstr_fd(1, " <==\n");
	}
	if (nbytes >= file_size)
		start = 0;
	else
		start = file_size - nbytes;
	write(1, content + start, file_size - start);
	free(content);
}

int	main(int argc, char **argv)
{
	int		nbytes;
	int		i;
	int		multiple_files;
	char	*prog;

	if (argc < 3)
	{
		print_error(argv[0], NULL, "usage: ft_tail -c N [file ...]");
		return (1);
	}
	prog = argv[0];
	if (strcmp(argv[1], "-c") != 0)
	{
		print_error(prog, NULL, "option -c required");
		return (1);
	}
	nbytes = 0;
	i = 0;
	while (argv[2][i])
	{
		if (argv[2][i] < '0' || argv[2][i] > '9')
		{
			print_error(prog, NULL, "invalid number");
			return (1);
		}
		nbytes = nbytes * 10 + (argv[2][i] - '0');
		i++;
	}
	if (nbytes < 0)
	{
		print_error(prog, NULL, "invalid number");
		return (1);
	}
	if (argc == 3)
	{
		print_tail(prog, NULL, nbytes, 0);
		return (0);
	}
	multiple_files = (argc - 3) > 1;
	i = 3;
	while (i < argc)
	{
		print_tail(prog, argv[i], nbytes, multiple_files);
		i++;
	}
	return (0);
}
