char *ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	int	j;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return dest;
}

#include <stdio.h>
int	main(void)
{
	char dest[20] = "Hello ";
	ft_strcat(dest, "World");
	printf("%s\n", dest);
	return (0);
}
