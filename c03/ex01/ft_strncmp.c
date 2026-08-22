int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return(s1[i] - s2[i]);
}

#include <stdio.h>

int	main (void)
{
	char s1[] = "abcdef";
	char s2[] = "abcdfe";
	printf("%d\n", ft_strncmp(s1, s2, 4));
	return(0);
}

