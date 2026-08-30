#include "bsq.h"

char *read_all(int fd, int *out_size)
{
    int capacity = 4096;
    int size = 0;
    char *buffer = malloc(capacity);
    
    if (!buffer)
        return NULL;
    
    int bytes_read;
    while ((bytes_read = read(fd, buffer + size, capacity - size)) > 0)
	{
        size += bytes_read;
        if (size == capacity)
		{
            capacity *= 2;
            char *new_buffer = malloc(capacity);
            if (!new_buffer)
			{
                free(buffer);
                return NULL;
            }
			int	i;
			i = 0;
			while (i < size)
			{
                new_buffer[i] = buffer[i];
				i++;
            }
            free(buffer);
            buffer = new_buffer;
        }
    }
    
    if (bytes_read < 0)
	{
        free(buffer);
        return NULL;
    }
    
    *out_size = size;
    return buffer;
}
