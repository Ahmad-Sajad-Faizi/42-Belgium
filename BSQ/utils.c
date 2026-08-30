#include "bsq.h"

int	ft_is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

void ft_puterror(void)
{
	write(1, "map error\n", 10);
}
