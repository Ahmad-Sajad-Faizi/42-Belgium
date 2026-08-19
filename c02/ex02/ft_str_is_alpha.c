int	ft_str_is_alpha(char *str)
{
	while(*str)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
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
	char *test1 = "HelloWorld";
	char *test2 = "Hello World";
	char *test3 = "Hello123";
	char *test4 = "";

	printf("Test 1 (HelloWorld): %d\n", ft_str_is_alpha(test1));
	printf("Test 2 (Hello World): %d\n", ft_str_is_alpha(test2));
	printf("Test 3 (Hello123): %d\n", ft_str_is_alpha(test3));
	printf("Test 4 (Empty): %d\n", ft_str_is_alpha(test4));

	return (0);
}

