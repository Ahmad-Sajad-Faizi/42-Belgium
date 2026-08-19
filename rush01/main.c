/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:00:00 by your_login        #+#    #+#             */
/*   Updated: 2026/08/15 10:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush01.h"

int	solve(int *clues, int n, int ***grid)
{
	int	*col_mask;
	int	row;
	int	col;

	*grid = (int **)malloc(n * sizeof(int *));
	if (!*grid)
		return (0);
	row = 0;
	while (row < n)
	{
		(*grid)[row] = (int *)malloc(n * sizeof(int));
		if (!(*grid)[row])
			return (0);
		row++;
	}
	col_mask = (int *)malloc(n * sizeof(int));
	if (!col_mask)
		return (0);
	col = 0;
	while (col < n)
	{
		col_mask[col] = 0;
		col++;
	}
	return (backtrack(0, *grid, col_mask, clues, n));
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	n;
	int	**grid;
	int	base[MAX_N];
	int	i;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (parse_input(argv[1], &clues, &n))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (i < n)
	{
		base[i] = i + 1;
		i++;
	}
	g_perm_count = 0;
	generate_permutations(base, 0, n);
	if (solve(clues, n, &grid))
	{
		print_grid(grid, n);
		// free memory
		i = 0;
		while (i < n)
			free(grid[i++]);
		free(grid);
	}
	else
		write(2, "Error\n", 6);
	free(clues);
	return (0);
}
