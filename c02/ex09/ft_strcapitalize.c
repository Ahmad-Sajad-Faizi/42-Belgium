char *ft_strcapitalize(char *str)
{
	char	*i;
	int	j;

	i = str;
	j = 1;
	while(*str)
	{
		if ((*str >= 'a' && *str <= 'z') ||
			(*str >= 'A' && *str <= 'Z') ||
			(*str >= '0' && *str <= '9'))
		{
			if (j)
			{
				if (*str >= 'a' && *str <= 'z')
					*str -= 32;
				j = 0;
			}
			else
			{
				if (*str >= 'A' && *str <= 'Z')
					*str += 32;
			}
		}
		else
		{
			j = 1;
		}
		str++;
	}
	return (i);
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
