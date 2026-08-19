void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 11;
	int b = 2;
	int div = 0;
	int mod = 0;
	printf("a: %d, b: %d, div: %d, mod: %d\n", a, b, div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("a: %d, b: %d div: %d, mod: %d\n",a, b, div, mod);
	return(0);
}
*/
