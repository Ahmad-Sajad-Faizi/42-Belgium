int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (index < n && s1[index] == s2[index] && s1[index] && s2[index])
		index++;
	if (index == n)
		return (0);
	return(s1[index] - s2[index]);
}

#include <stdio.h>

int	main (void)
{
	char s1[] = "abcdef";
	char s2[] = "abcdfe";
	printf("%d\n", ft_strncmp(s1, s2, 4));
	return(0);
}

