void	ft_ultimate_div_mod(int *a,int *b)
{
	int tmp;
	tmp = *a;
	*a = tmp / *b;
	*b = tmp % *b;
}
/*
#include <stdio.h>

int main(void)
{
	int a = 21;
	int b = 2;

	printf("Before ft_ultimate_div_mod: a:%d, b:%d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("After ft_ultimate_div_mod: a:%d, b:%d\n", a, b);
	return(0);
}
*/
