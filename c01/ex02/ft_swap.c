void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>
int	main(void)
{
	int a;
	int b;
	a = 5;
	b = 7;
	printf("before ft_swap: a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("after ft_swap: a = %d, b = %d\n", a, b);
	return(0);
}
