char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "this is just a text.";
	char dest[50];

	printf("src: %s\n", src);
	ft_strcpy(dest, src);
	printf("dest: %s\n", dest);
	return(0);
}
*/
