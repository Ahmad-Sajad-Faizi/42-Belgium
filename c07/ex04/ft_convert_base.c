#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
char	*ft_putnbr_base(int nbr, char *base);
int	ft_strlen(char *str);
int	check_base(char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	value;
	char	*result;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	value = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(value, base_to);
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	char *res;
	res = ft_convert_base("  ---+42", "0123456789", "0123456789ABCDEF");
	printf("Dec to Hex ('-42'): %s (Expected: -2A)\n", res);
	if (res) 
		free(res);
	res = ft_convert_base("101010", "01", "0123456789");
	printf("Bin to Dec ('101010'): %s (Expected: 42)\n", res);
	if (res) 
		free(res);
	res = ft_convert_base("2A", "0123456789ABCDEF", "poneyvif");
	printf("Hex to Oct ('2A'): %s (Expected: pf)\n", res);
	if (res)
       		free(res);
	res = ft_convert_base("42", "0123456789+", "01");
	printf("Invalid base_from: %p (Expected: (nil))\n", (void *)res);
	if (res)
       		free(res);
	return (0);
}
*/
