char *ft_strlowcase(char *str)
{
	char *i;

	i = str;
	while(*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str+= 32;
		}
		str++;
	}
	return(i);
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
