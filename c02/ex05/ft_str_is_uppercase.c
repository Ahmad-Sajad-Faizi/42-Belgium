int	ft_str_is_uppercase(char *str)
{
	while(*str)
	{
		if (!(*str >= 'A' && *str <= 'Z'))
		{
			return(0);
		}
		str++;
	}
	return(1);
}
/*
#include <stdio.h>

int	main(void)
{
	char *test1 = "ADSFASDF";
	char *test2 = "ASDF ADSF";
	char *test3 = "123465";
	char *test4 = "";

	printf("test 1 (ASDFASDF): %d\n", ft_str_is_uppercase(test1));
	printf("test 2 (ASDF ADSF): %d\n", ft_str_is_uppercase(test2));
	printf("test 3 (123456): %d\n", ft_str_is_uppercase(test3));
	printf("test 4 (): %d\n", ft_str_is_uppercase(test4));
	return(0);
}
*/
