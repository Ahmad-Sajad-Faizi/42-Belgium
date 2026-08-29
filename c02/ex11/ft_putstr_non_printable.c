#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_put_hex(unsigned char c)
{
	char *hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}
void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			ft_putchar(str[i]);
		}
		else
			ft_put_hex(str[i]);
		i++;
	}
}
/*
int	main(void)
{
	char str[] = "Hello\nHow are you?";
	ft_putstr_non_printable(str);
	ft_putchar('\n');	
	return(0);
}
*/
