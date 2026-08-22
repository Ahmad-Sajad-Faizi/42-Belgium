#include "rush01.h"

static int	used_in_row(int grid[SIZE][SIZE], int row, int num)
{
	int	col = 0;
	while (col < SIZE)
	{
		if (grid[row][col] == num)
			return (1);
		col++;
	}
	return (0);
}

static int	used_in_col(int grid[SIZE][SIZE], int col, int num)
{
	int	row = 0;
	while (row < SIZE)
	{
		if (grid[row][col] == num)
			return (1);
		row++;
	}
	return (0);
}

static int	is_safe(int grid[SIZE][SIZE], int row, int col, int num)
{
	return (!used_in_row(grid, row, num) && !used_in_col(grid, col, num));
}

static void	reverse_array(int src[SIZE], int dst[SIZE])
{
	int	i = 0;
	while (i < SIZE)
	{
		dst[i] = src[SIZE - 1 - i];
		i++;
	}
}

static int	check_row(int grid[SIZE][SIZE], int row, int left, int right)
{
	int	rev[SIZE];
	reverse_array(grid[row], rev);
	return (count_visible(grid[row], SIZE) == left &&
			count_visible(rev, SIZE) == right);
}

static int	check_col(int grid[SIZE][SIZE], int col, int top, int bottom)
{
	int	arr[SIZE];
	int	rev[SIZE];
	int	row = 0;
	while (row < SIZE)
	{
		arr[row] = grid[row][col];
		row++;
	}
	reverse_array(arr, rev);
	return (count_visible(arr, SIZE) == top &&
			count_visible(rev, SIZE) == bottom);
}

int	solve(int grid[SIZE][SIZE], int top[SIZE], int bottom[SIZE],
			int left[SIZE], int right[SIZE], int pos)
{
	int	row, col;

	if (pos == SIZE * SIZE)
	{
		int	i = 0;
		while (i < SIZE)
		{
			if (!check_row(grid, i, left[i], right[i]))
				return (0);
			if (!check_col(grid, i, top[i], bottom[i]))
				return (0);
			i++;
		}
		return (1);
	}

	row = pos / SIZE;
	col = pos % SIZE;

	if (grid[row][col] != 0)
		return (solve(grid, top, bottom, left, right, pos + 1));

	int	num = 1;
	while (num <= SIZE)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;

			if (col == SIZE - 1)
			{
				if (!check_row(grid, row, left[row], right[row]))
				{
					grid[row][col] = 0;
					num++;
					continue;
				}
			}
			if (row == SIZE - 1)
			{
				if (!check_col(grid, col, top[col], bottom[col]))
				{
					grid[row][col] = 0;
					num++;
					continue;
				}
			}

			if (solve(grid, top, bottom, left, right, pos + 1))
				return (1);

			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
