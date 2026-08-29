char *ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return(str);
}
/*
#include <stdio.h>
int	main(void)
{
	char test1[] = "HELLO WORLD";
	printf("before: %s\n", test1);
	ft_strlowcase(test1);
	printf("after: %s\n", test1);
	return(0);
}
*/
