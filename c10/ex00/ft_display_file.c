#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

void	display_file(char *filename)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	while ((bytes = read(fd, buf, BUF_SIZE)) > 0)
		write(1, buf, bytes);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	display_file(argv[1]);
	return (0);
}
