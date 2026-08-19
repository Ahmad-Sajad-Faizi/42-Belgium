/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:00:00 by your_login        #+#    #+#             */
/*   Updated: 2026/08/15 10:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define MAX_N 9
# define MAX_PERMS 362880  // 9!

extern int	g_perms[MAX_PERMS][MAX_N];
extern int	g_left_vis[MAX_PERMS];
extern int	g_right_vis[MAX_PERMS];
extern int	g_perm_count;
extern int	g_n;  // current grid size

int		visible_count(int *arr, int size);
void	save_permutation(int *arr, int n);
void	generate_permutations(int *arr, int start, int n);
int		parse_input(char *str, int **clues, int *n);
void	place_row(int row, int p, int **grid, int *col_mask, int n);
void	unplace_row(int p, int *col_mask, int n);
int		check_column_clues(int **grid, int *clues, int n);
int		check_row_visibility(int p, int row, int *clues, int n);
int		has_column_conflict(int p, int *col_mask, int n);
int		backtrack(int row, int **grid, int *col_mask, int *clues, int n);
int		solve(int *clues, int n, int ***grid);
void	print_grid(int **grid, int n);

#endif
