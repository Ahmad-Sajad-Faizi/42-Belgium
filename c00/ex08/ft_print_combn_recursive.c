#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_combn_recursive(char *comb, int n, int pos, char start)
{
    char c;
    int i;

    if (pos == n)
    {
        i = 0;
        while (i < n)
        {
            ft_putchar(comb[i]);
            i++;
        }
        if (comb[0] != '9' - n + 1)
            write(1, ", ", 2);
        return;
    }
    c = start;
    while (c <= '9')
    {
        comb[pos] = c;
        ft_print_combn_recursive(comb, n, pos + 1, c + 1);
        c++;
    }
}

void ft_print_combn(int n)
{
    char comb[10];
    if (n > 0 && n < 10)
        ft_print_combn_recursive(comb, n, 0, '0');
}

int main(void)
{
    ft_print_combn(2);
    ft_putchar('\n');
    return (0);
}
