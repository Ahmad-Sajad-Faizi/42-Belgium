#include "rush.h"

static void	print_rectangle(int x, int y,
				char tl, char tr, char bl, char br,
				char hor, char ver)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0)
		return ;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			if (row == 0 && col == 0)
				ft_putchar(tl);
			else if (row == 0 && col == x - 1)
				ft_putchar(tr);
			else if (row == y - 1 && col == 0)
				ft_putchar(bl);
			else if (row == y - 1 && col == x - 1)
				ft_putchar(br);
			else if (row == 0 || row == y - 1)
				ft_putchar(hor);
			else if (col == 0 || col == x - 1)
				ft_putchar(ver);
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	rush00(int x, int y)
{
	print_rectangle(x, y, 'o', 'o', 'o', 'o', '-', '|');
}

void	rush01(int x, int y)
{
	print_rectangle(x, y, '/', '\\', '\\', '/', '*', '*');
}

void	rush02(int x, int y)
{
	print_rectangle(x, y, 'A', 'A', 'C', 'C', 'B', 'B');
}

void	rush03(int x, int y)
{
	print_rectangle(x, y, 'A', 'C', 'A', 'C', 'B', 'B');
}

void	rush04(int x, int y)
{
	print_rectangle(x, y, 'A', 'C', 'C', 'A', 'B', 'B');
}
