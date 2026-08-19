/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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

int	visible_count(int *arr, int size)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			count++;
			max = arr[i];
		}
		i++;
	}
	return (count);
}

int	parse_input(char *str, int **clues, int *n)
{
	int	count;
	int	*temp;
	int	num;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		if (str[i] < '1' || str[i] > '9')
			return (1);
		count++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (count % 4 != 0 || count / 4 < 4 || count / 4 > 9)
		return (1);
	*n = count / 4;
	temp = (int *)malloc(count * sizeof(int));
	if (!temp)
		return (1);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		num = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		if (num < 1 || num > *n)
		{
			free(temp);
			return (1);
		}
		temp[count++] = num;
	}
	*clues = temp;
	return (0);
}

void	place_row(int row, int p, int **grid, int *col_mask, int n)
{
	int	c;

	c = 0;
	while (c < n)
	{
		grid[row][c] = g_perms[p][c];
		col_mask[c] |= (1 << (g_perms[p][c] - 1));
		c++;
	}
}

void	unplace_row(int p, int *col_mask, int n)
{
	int	c;

	c = 0;
	while (c < n)
	{
		col_mask[c] &= ~(1 << (g_perms[p][c] - 1));
		c++;
	}
}

void	print_grid(int **grid, int n)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < n - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
