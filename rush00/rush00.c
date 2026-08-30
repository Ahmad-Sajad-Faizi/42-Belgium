#include <unistd.h>

void	rush(int x, int y)
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
			if (row == 0 || row == y - 1)
			{
				if (col == 0 || col == x - 1)
					write(1, "o", 1);
				else
					write(1, "-", 1);
			}
			else
			{
				if (col == 0 || col == x - 1)
					write(1, "|", 1);
				else
					write(1, " ", 1);
			}
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
