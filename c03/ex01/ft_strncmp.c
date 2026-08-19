int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && *s1 == *s2 && *s1)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return(*s1 - *s2);
}

#include <stdio.h>

int	main (void)
{
	char s1[] = "abcdef";
	char s2[] = "abcdfe";
	printf("%d\n", ft_strncmp(s1, s2, 4));
	return(0);
}

