#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	hundreds;
	char	tens;
	char	units;

	hundreds = '0';
	while (hundreds <= '7')
		{
			tens = hundreds + 1;
			while (tens <= '8')
			{
				units = tens + 1;
				while (units <= '9')
				{
					ft_putchar(hundreds);
					ft_putchar(tens);
					ft_putchar(units);
					if (!(hundreds == '7' && tens == '8' && units == '9'))
					{
						ft_putchar(',');
						ft_putchar(' ');
					}
					units++;
				}
				tens++;
			}
			hundreds++;
		}
}
/*
int	main(void)
{
	ft_print_comb();
	ft_putchar('\n');
	return(0);
}
*/
