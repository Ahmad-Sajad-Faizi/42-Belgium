int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] && s2[index])
		index++;
	return (s1[index] - s2[index]);
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
