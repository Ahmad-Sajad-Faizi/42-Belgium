/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:00:00 by your_login        #+#    #+#             */
/*   Updated: 2026/08/15 10:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

int	check_column_clues(int **grid, int *clues, int n)
{
	int	c;
	int	*col;
	int	*rev;
	int	i;

	c = 0;
	while (c < n)
	{
		col = (int *)malloc(n * sizeof(int));
		rev = (int *)malloc(n * sizeof(int));
		if (!col || !rev)
			return (0);
		i = 0;
		while (i < n)
		{
			col[i] = grid[i][c];
			rev[i] = grid[n - 1 - i][c];
			i++;
		}
		if (visible_count(col, n) != clues[c] ||
			visible_count(rev, n) != clues[n + c])
		{
			free(col);
			free(rev);
			return (0);
		}
		free(col);
		free(rev);
		c++;
	}
	return (1);
}

int	check_row_visibility(int p, int row, int *clues, int n)
{
	if (g_left_vis[p] != clues[2 * n + row])
		return (0);
	if (g_right_vis[p] != clues[3 * n + row])
		return (0);
	return (1);
}

int	has_column_conflict(int p, int *col_mask, int n)
{
	int	c;
	int	num;

	c = 0;
	while (c < n)
	{
		num = g_perms[p][c];
		if (col_mask[c] & (1 << (num - 1)))
			return (1);
		c++;
	}
	return (0);
}

int	backtrack(int row, int **grid, int *col_mask, int *clues, int n)
{
	int	p;
	int	conflict;

	if (row == n)
		return (check_column_clues(grid, clues, n));
	p = 0;
	while (p < g_perm_count)
	{
		if (check_row_visibility(p, row, clues, n))
		{
			conflict = has_column_conflict(p, col_mask, n);
			if (!conflict)
			{
				place_row(row, p, grid, col_mask, n);
				if (backtrack(row + 1, grid, col_mask, clues, n))
					return (1);
				unplace_row(p, col_mask, n);
			}
		}
		p++;
	}
	return (0);
}
