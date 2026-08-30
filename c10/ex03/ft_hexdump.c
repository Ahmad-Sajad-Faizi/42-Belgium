#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define BUF_SIZE 16
#define HEX_CHARS "0123456789abcdef"

void	ft_putstr_fd(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
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

void	print_offset(unsigned int offset)
{
	int		i;
	char	hex[8];

	i = 7;
	while (i >= 0)
	{
		hex[i] = HEX_CHARS[offset & 0xF];
		offset >>= 4;
		i--;
	}
	write(1, hex, 8);
	write(1, "  ", 2);
}

void	print_hex_line(unsigned char *buf, int len, unsigned int offset)
{
	int	i;

	print_offset(offset);
	i = 0;
	while (i < 16)
	{
		if (i < len)
		{
			write(1, &HEX_CHARS[buf[i] >> 4], 1);
			write(1, &HEX_CHARS[buf[i] & 0xF], 1);
		}
		else
		{
			write(1, "  ", 2);
		}
		if (i == 7)
			write(1, " ", 1);
		else if (i < 15)
			write(1, " ", 1);
		i++;
	}
	write(1, " |", 2);
	i = 0;
	while (i < len)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			write(1, &buf[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	process_data(unsigned char *data, unsigned int total_bytes)
{
	unsigned int	offset;
	unsigned int	i;

	offset = 0;
	i = 0;
	while (i < total_bytes)
	{
		unsigned int	chunk = (total_bytes - i < 16) ? (total_bytes - i) : 16;
		print_hex_line(data + i, chunk, offset);
		i += chunk;
		offset += chunk;
	}
	print_offset(total_bytes);
	write(1, "\n", 1);
}

unsigned char	*read_all_input(int *total_bytes, char *prog, char **files, int file_count)
{
	unsigned char	*all;
	unsigned char	buf[BUF_SIZE];
	int				fd;
	int				bytes;
	int				total;
	int				i;

	all = NULL;
	total = 0;
	if (file_count == 0)
	{
		fd = 0;
		while ((bytes = read(fd, buf, BUF_SIZE)) > 0)
		{
			all = realloc(all, total + bytes);
			if (!all)
			{
				print_error(prog, NULL, "memory error");
				free(all);
				*total_bytes = -1;
				return (NULL);
			}
			int j = 0;
			while (j < bytes)
			{
				all[total + j] = buf[j];
				j++;
			}
			total += bytes;
		}
		*total_bytes = total;
		return (all);
	}
	i = 0;
	while (i < file_count)
	{
		fd = open(files[i], O_RDONLY);
		if (fd < 0)
		{
			print_error(prog, files[i], strerror(errno));
		}
		else
		{
			while ((bytes = read(fd, buf, BUF_SIZE)) > 0)
			{
				all = realloc(all, total + bytes);
				if (!all)
				{
					print_error(prog, NULL, "memory error");
					free(all);
					*total_bytes = -1;
					if (fd != 0)
						close(fd);
					return (NULL);
				}
				int j = 0;
				while (j < bytes)
				{
					all[total + j] = buf[j];
					j++;
				}
				total += bytes;
			}
			close(fd);
		}
		i++;
	}
	*total_bytes = total;
	return (all);
}

int	main(int argc, char **argv)
{
	unsigned char	*data;
	int				total_bytes;

	if (argc < 2)
	{
		print_error(argv[0], NULL, "usage: ft_hexdump -C [file ...]");
		return (1);
	}
	if (strcmp(argv[1], "-C") != 0)
	{
		print_error(argv[0], NULL, "option -C required");
		return (1);
	}
	data = read_all_input(&total_bytes, argv[0], &argv[2], argc - 2);
	if (total_bytes < 0)
	{
		free(data);
		return (1);
	}
	if (total_bytes > 0)
		process_data(data, total_bytes);
	free(data);
	return (0);
}
