int	ft_str_is_lowercase(char *str)
{
	while(*str)
	{
		if (!(*str >= 'a' && *str <= 'z'))
		{
			return(0);
		}
		str++;
	}
	return(1);
}

#include <stdio.h>

int main(void)
{
	char *test1 = "asdfasfd";
	char *test2 = "ASDFASDA";
	char *test3 = "";
	char *test4 = "123456";

	printf("test 1 (asdfasfd): %d\n", ft_str_is_lowercase(test1));
	printf("test 2 (ASDFASDA): %d\n", ft_str_is_lowercase(test2));
	printf("test 3 (): %d\n", ft_str_is_lowercase(test3));
	printf("test 4 (123456): %d\n", ft_str_is_lowercase(test4));
	return(0);
}

