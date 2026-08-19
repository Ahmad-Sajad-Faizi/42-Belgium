#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr_hex(unsigned long nb, int padding)
{
    char    *hex = "0123456789abcdef";

    if (padding > 1)
        ft_putnbr_hex(nb / 16, padding - 1);
    ft_putchar(hex[nb % 16]);
}

void    ft_print_addr(unsigned long addr)
{
    ft_putnbr_hex(addr, 16);
    ft_putchar(':');
    ft_putchar(' ');
}

void    ft_print_hex_content(unsigned char *ptr, unsigned int remaining)
{
    unsigned int    i;
    char            *hex;

	hex = "0123456789abcdef";
    i = 0;
    while (i < 16)
    {
        if (i < remaining)
        {
            ft_putchar(hex[ptr[i] / 16]);
            ft_putchar(hex[ptr[i] % 16]);
        }
        else
        {
            ft_putchar(' ');
            ft_putchar(' ');
        }
        if (i % 2 == 1)
            ft_putchar(' ');
        i++;
    }
}

void    ft_print_str_content(unsigned char *ptr, unsigned int remaining)
{
    unsigned int    i;

    i = 0;
    while (i < 16 && i < remaining)
    {
        if (ptr[i] >= 32 && ptr[i] <= 126)
            ft_putchar(ptr[i]);
        else
            ft_putchar('.');
        i++;
    }
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    unsigned char   *ptr;
    unsigned int    i;

    if (size == 0)
        return (addr);

    ptr = (unsigned char *)addr;
    i = 0;
    while (i < size)
    {
        ft_print_addr((unsigned long)(ptr + i));
        ft_print_hex_content(ptr + i, size - i);
        ft_print_str_content(ptr + i, size - i);
        ft_putchar('\n');
        i += 16;
    }
    return (addr);
}

int main(void)
{
    char    str[] = "Bonjour les aminches\n\tc est fou\ttout ce qu on peut faire avec\r\n\tprint_memory\r\n\n\tlol.lol\n \0";
    ft_print_memory(str, sizeof(str));
    return (0);
}
