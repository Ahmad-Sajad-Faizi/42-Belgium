#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int	i;
	char	*hex_base;

	i = 0;
	hex_base = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			write(1, &hex_base[(unsigned char)str[i] / 16], 1);
			write(1, &hex_base[(unsigned char)str[i] % 16], 1);
		}
		i++;
	}
}
/*
int	main(void)
{
	char str[] = "Hello\nHow are you?";
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	return(0);
}
*/
