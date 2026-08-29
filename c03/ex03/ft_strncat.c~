char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	i = 0;
	while (dest[i])
		i++;
	unsigned int j;
	j = 0;
	while (j < nb && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return dest;
}
#include <stdio.h>
int main(void)
{
	char dest[20] = "Hello ";
	ft_strncat(dest, "World!", 3);
	printf("%s\n", dest);
	return 0;
}
