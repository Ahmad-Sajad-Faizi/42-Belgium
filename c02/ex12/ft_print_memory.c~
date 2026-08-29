#include <unistd.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hex(unsigned long number, int padding)
{
	char	*hex = "0123456789abcdef";

	if (padding > 1)
		ft_putnbr_hex(number / 16, padding - 1);
	ft_putchar(hex[number % 16]);
}

void	ft_print_addr(unsigned long address)
{
	ft_putnbr_hex(address, 16);
	ft_putchar(':');
	ft_putchar(' ');
}

void	ft_print_hex_content(unsigned char *pointer, unsigned int remaining)
{
	unsigned int	index;
	char			*hex;

	hex = "0123456789abcdef";
	index = 0;
	while (index < 16)
	{
		if (index < remaining)
		{
			ft_putchar(hex[pointer[index] / 16]);
			ft_putchar(hex[pointer[index] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (index % 2 == 1)
			ft_putchar(' ');
		index++;
	}
}

void	ft_print_str_content(unsigned char *pointer, unsigned int remaining)
{
	unsigned int	index;

	index = 0;
	while (index < 16 && index < remaining)
	{
		if (pointer[index] >= 32 && pointer[index] <= 126)
			ft_putchar(pointer[index]);
		else
			ft_putchar('.');
		index++;
	}
}

void	*ft_print_memory(void *address, unsigned int size)
{
	unsigned char   *pointer;
	unsigned int    index;

	if (size == 0)
		return (address);

	pointer = (unsigned char *)address;
	index = 0;
	while (index < size)
	{
		ft_print_addr((unsigned long)(pointer + index));
		ft_print_hex_content(pointer + index, size - index);
		ft_print_str_content(pointer + index, size - index);
		ft_putchar('\n');
		index += 16;
	}
	return (address);
}

int main(void)
{
    char    string[] = "Bonjour les aminches\n\tc est fou\ttout ce qu on peut faire avec\r\n\tprint_memory\r\n\n\tlol.lol\n \0";
    ft_print_memory(string, sizeof(string));
    return (0);
}
