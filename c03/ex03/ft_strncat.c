char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;
	unsigned int	i;

	ptr = dest;
	while (*ptr)
		ptr++;
	i = 0;
	while (i < nb && src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	char dest[20] = "Hello ";
	ft_strncat(dest, "World!", 3);
	printf("%s\n", dest);
	return 0;
}
*/
