#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdio.h>

#define BUF_SIZE 30000

void	ft_putstr_fd(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	display_file(char *prog, char *filename)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(2, basename(prog));
		ft_putstr_fd(2, ": ");
		ft_putstr_fd(2, filename);
		ft_putstr_fd(2, ": ");
		ft_putstr_fd(2, strerror(errno));
		ft_putstr_fd(2, "\n");
		return ;
	}
	while ((bytes = read(fd, buf, BUF_SIZE)) > 0)
		write(1, buf, bytes);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		char	buf[BUF_SIZE];
		int		bytes;
		while ((bytes = read(0, buf, BUF_SIZE)) > 0)
			write(1, buf, bytes);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			display_file(argv[0], argv[i]);
			i++;
		}
	}
	return (0);
}
