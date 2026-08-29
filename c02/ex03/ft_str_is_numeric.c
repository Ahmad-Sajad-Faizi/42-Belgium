int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
				return(0);
		}
		i++;
	}
	return(1);
}
/*
#include <stdio.h>
int	main(void)
{
	char *test1 = "123456987";
	char *test2 = "";
	char *test3 = "123546 456123";
	char *test4 = "sdafasdfj";

	printf("test 1 (123456987): %d\n", ft_str_is_numeric(test1));
	printf("test 2 (): %d\n", ft_str_is_numeric(test2));
	printf("test 3 (123546 456123): %d\n", ft_str_is_numeric(test3));
	printf("test 4 (sdafasdfj): %d\n", ft_str_is_numeric(test4));
	return(0);
}
*/
