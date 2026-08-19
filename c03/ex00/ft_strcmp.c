int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
#include <stdio.h>
int	main(void)
{
	char s1[] = "abc";
	char s2[] = "acd";
	int a = ft_strcmp(s1, s2);
	printf("strcmp output: %d\n", a);
	return(0);
}
*/
