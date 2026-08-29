int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("Length of 'Hello': %d\n", ft_strlen("Hello"));
	return (0);
}
*/
