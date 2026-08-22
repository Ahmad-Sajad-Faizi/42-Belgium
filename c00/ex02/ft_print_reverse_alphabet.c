#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c++;
	}
}
/*
int	main(void)
{
	ft_print_reverse_alphabet();
	write(1, "/n", 1);
	return(0);
}
*/
