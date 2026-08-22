#include "rush01.h"

void	print_grid(int grid[SIZE][SIZE])
{
	int	row, col;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			char	c = '0' + grid[row][col];
			write(1, &c, 1);
			if (col < SIZE - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
