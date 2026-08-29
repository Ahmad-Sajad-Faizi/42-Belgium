unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (src[i])
	{
		i++;
	}
	if (size == 0)
	{
		return (i);
	}
	j = 0;
	while (src[j] && i < size - 1)
	{
		dest[j] = src [j];
		j++;
	}
	dest [j] = '\0';
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	char src[] = "Hello world";
	char dest[30];
	unsigned int result;

	result = ft_strlcpy(dest, src, 30);
	printf("Test 1: dest = '%s', return = %u\n", dest, result);
	return(0);
}
*/
