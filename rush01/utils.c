#include "rush01.h"

int	ft_atoi(const char *str)
{
	int	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}
