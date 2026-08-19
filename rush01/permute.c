/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:00:00 by your_login        #+#    #+#             */
/*   Updated: 2026/08/15 10:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	g_perms[MAX_PERMS][MAX_N];
int	g_left_vis[MAX_PERMS];
int	g_right_vis[MAX_PERMS];
int	g_perm_count;
int	g_n;

void	save_permutation(int *arr, int n)
{
	int	i;
	int	rev[MAX_N];

	i = 0;
	while (i < n)
	{
		g_perms[g_perm_count][i] = arr[i];
		i++;
	}
	g_left_vis[g_perm_count] = visible_count(g_perms[g_perm_count], n);
	i = 0;
	while (i < n)
	{
		rev[i] = g_perms[g_perm_count][n - 1 - i];
		i++;
	}
	g_right_vis[g_perm_count] = visible_count(rev, n);
	g_perm_count++;
}

void	generate_permutations(int *arr, int start, int n)
{
	int	i;
	int	tmp;

	if (start == n)
	{
		save_permutation(arr, n);
		return ;
	}
	i = start;
	while (i < n)
	{
		tmp = arr[start];
		arr[start] = arr[i];
		arr[i] = tmp;
		generate_permutations(arr, start + 1, n);
		tmp = arr[start];
		arr[start] = arr[i];
		arr[i] = tmp;
		i++;
	}
}
