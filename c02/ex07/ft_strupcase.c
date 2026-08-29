char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return(str);
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
