char	*ft_strupcase(char *str)
{
	char *i;

	i = str;
	while(*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 32;
		}
		str++;
	}
	return(i);
}
/*
#include <stdio.h>
int	main(void)
{
	char test1[] = "hello world.";
	printf("before: %s\n", test1);
	ft_strupcase(test1);
	printf("after: %s\n", test1);
	return(0);
}
*/
