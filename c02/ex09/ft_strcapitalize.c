char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize_next;

	i = 0;
	capitablize_next = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (capitablize_next)
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!capitablize_next)
				str[i] += 32;
		}
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
			capitablize_next = 0;
		else
			capitablize_next = 1;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main (void)
{
	char str[] = "hi, how are you? 42words forty-two; fifty+and+one";

	printf("before: %s\n", str);
	ft_strcapitalize(str);
	printf("after: %s\n", str);
	return(0);
}
*/
