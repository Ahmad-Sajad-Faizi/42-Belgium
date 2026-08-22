#include "rush01.h"

static int	parse_numbers(const char *str, int nums[SIZE * SIZE])
{
	int	i = 0;
	int	val;

	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str == '\0')
			break;
		if (*str < '0' || *str > '9')
			return (0);
		val = ft_atoi(str);
		if (val < 1 || val > SIZE)
			return (0);
		if (i >= SIZE * SIZE)
			return (0);
		nums[i++] = val;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return (i == SIZE * SIZE);
}

int	main(int argc, char **argv)
{
	int	nums[SIZE * SIZE];
	int	top[SIZE], bottom[SIZE], left[SIZE], right[SIZE];
	int	grid[SIZE][SIZE] = {0};
	int	i;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!parse_numbers(argv[1], nums))
	{
		ft_putstr("Error\n");
		return (1);
	}

	i = 0;
	while (i < SIZE)
	{
		top[i] = nums[i];
		bottom[i] = nums[SIZE + i];
		left[i] = nums[2 * SIZE + i];
		right[i] = nums[3 * SIZE + i];
		i++;
	}

	if (!solve(grid, top, bottom, left, right, 0))
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_grid(grid);
	return (0);
}
