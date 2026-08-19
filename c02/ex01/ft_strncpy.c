char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *i;

	i = dest;
	while(n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}
	return(i);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "This is just a text.";
	char dest[50];
	printf("src: %s\n", src);
	ft_strncpy(dest, src, 8);
	printf("dest: %s\n",dest);
	return(0);
}
*/
