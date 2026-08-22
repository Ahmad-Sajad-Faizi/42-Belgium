#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

# define SIZE 4

int		ft_atoi(const char *str);
void	ft_putstr(const char *str);

int		count_visible(int *arr, int n);

int		solve(int grid[SIZE][SIZE], int top[SIZE], int bottom[SIZE],
			  int left[SIZE], int right[SIZE], int pos);

void	print_grid(int grid[SIZE][SIZE]);

#endif
