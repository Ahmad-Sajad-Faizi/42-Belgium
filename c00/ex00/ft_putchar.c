#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_putchar('a');
	write(1, "\n", 1);
	ft_putchar('b');
}
