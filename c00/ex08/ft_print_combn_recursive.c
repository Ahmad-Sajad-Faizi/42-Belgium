#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_combination(int n, int *digits, int index, int start)
{
    if (index == n)
    {
        int i;
		i = 0;
		while(i < n)
		{
			ft_putchar(digits[i] + '0');
			i++;
		}
        if (digits[0] != 10 - n)
		{
            ft_putchar(',');
            ft_putchar(' ');
        }
        return;
    }
	int	i;
	i = start;
	while(i <= 9)
    {
        digits[index] = i;
        ft_print_combination(n, digits, index + 1, i + 1);
		i++;
    }
}
/*
void ft_print_combn(int n)
{
    if (n <= 0 || n >= 10)
        return;
    int digits[10];
    ft_print_combination(n, digits, 0, 0);
}
int main(void)
{
    ft_print_combn(2);
    ft_putchar('\n');
    return (0);
}
*/
