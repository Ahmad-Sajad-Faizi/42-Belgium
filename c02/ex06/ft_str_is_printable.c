int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
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
	char *test1 = "\n\a\b";
	char *test2 = "123dsf./";
	char *test3 = "";
	char *test4 = "asdf 123";

	printf("test 1 (\\n\\a\\b): %d\n", ft_str_is_printable(test1));
	printf("test 2 (123dsf./): %d\n", ft_str_is_printable(test2));
	printf("test 3 (): %d\n", ft_str_is_printable(test3));
	printf("test 4 (asdf 123): %d\n", ft_str_is_printable(test4));
	return(0);
}
*/
