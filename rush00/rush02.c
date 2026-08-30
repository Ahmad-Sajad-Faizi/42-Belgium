#include <unistd.h>

void	rush(int x, int y)
{
	int	col;
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			if (row == 0 && col == 0)
				write(1, "A", 1);
			else if (row == 0 && col == x - 1)
				write(1, "A", 1);
			else if (row == y - 1 && col == 0)
				write(1, "C", 1);
			else if (row == y - 1 && col == x - 1)
				write(1, "C", 1);
			else if (row == 0 || row == y - 1)
				write(1, "B", 1);
			else if (col == 0 || col == x - 1)
				write(1, "B", 1);
			else
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
