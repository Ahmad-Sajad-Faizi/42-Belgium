#include <unistd.h>

void	ft_putstr(char *str)
{

	while(*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}
/*
int	main(void)
{
	ft_putstr("What's up.");
	return(0);
}
*/
