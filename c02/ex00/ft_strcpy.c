char	*ft_strcpy(char *dest, char *src)
{
	char *i;

	i = dest;
	while(*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return(i);
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
