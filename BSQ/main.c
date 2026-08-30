#include "bsq.h"

int process_fd(int fd)
{
    int size;
	size = 0;
    char *buffer;
	buffer = read_all(fd, &size);
    
    if (!buffer)
	{
        ft_puterror();
        return 1;
    }
    t_map map;
    if (!parse_map(buffer, size, &map))
	{
        ft_puterror();
        free(buffer);
        return 1;
    }
    solve_map(&map);
    free(buffer);
    return 0;
}
int main(int argc, char **argv)
{
    if (argc == 1)
	{
        return process_fd(0);
    }
    int exit_status;
	exit_status = 0;
    int i;
	i = 1;
    while (i < argc)
	{
        if (i > 1)
		{
            write(1, "\n", 1);
        }
        int fd;
		fd = open(argv[i], O_RDONLY);
        if (fd < 0)
		{
            ft_puterror();
            exit_status = 1;
            i++;
            continue;
        }
        
        if (process_fd(fd) != 0)
		{
            exit_status = 1;
        }
        close(fd);
        i++;
    }
    return exit_status;
}
