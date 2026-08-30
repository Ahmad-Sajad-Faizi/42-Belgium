#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_add(int a, int b)	{ return (a + b); }
int	ft_sub(int a, int b)	{ return (a - b); }
int	ft_mul(int a, int b)	{ return (a * b); }
int	ft_div(int a, int b)	{ return (a / b); }
int	ft_mod(int a, int b)	{ return (a % b); }

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		(*ops[5])(int, int);
	char	*op;
	int		i;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = argv[2];
	ops[0] = &ft_add;
	ops[1] = &ft_sub;
	ops[2] = &ft_mul;
	ops[3] = &ft_div;
	ops[4] = &ft_mod;
	i = 0;
	while (i < 5)
	{
		if (op[0] == '+' && i == 0) break;
		if (op[0] == '-' && i == 1) break;
		if (op[0] == '*' && i == 2) break;
		if (op[0] == '/' && i == 3) break;
		if (op[0] == '%' && i == 4) break;
		i++;
	}
	if (i == 5)
	{
		ft_putnbr(0);
		return (0);
	}
	if (i == 3 && b == 0)
	{
		ft_putstr("Stop : division by zero");
		return (0);
	}
	if (i == 4 && b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (0);
	}
	ft_putnbr(ops[i](a, b));
	return (0);
}
