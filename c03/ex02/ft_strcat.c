char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char dest[20] = "Hello ";
	ft_strcat(dest, "World");
	printf("%s\n", dest);
	return (0);
}
*/
