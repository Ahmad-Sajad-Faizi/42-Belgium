int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
				{
					return(0);
				}
				i++;
	}
	return(1);
}
/*
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
*/
