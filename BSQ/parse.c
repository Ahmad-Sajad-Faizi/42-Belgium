#include "bsq.h"

int parse_map(char *buffer, int size, t_map *map)
{
    int newline_idx;
	newline_idx = -1;
	int i;
	i = 0;
	while(i < size)
	{
		if (buffer[i] == '\n')
		{
            newline_idx = i;
            break;
        }
		i++;
    }
    if (newline_idx < 4)
        return 0;

    char full;
	full = buffer[newline_idx - 1];
    char obs;
	obs = buffer[newline_idx - 2];
    char empty;
	empty = buffer[newline_idx - 3];

    if (full == obs || full == empty || obs == empty)
        return 0;
    if (!ft_is_printable(full) || !ft_is_printable(obs) || !ft_is_printable(empty))
        return 0;

    int rows;
	rows = 0;
	int j;
	j = 0;
	while (j <= newline_idx -4)
	{
		if (buffer[i] < '0' || buffer[i] > '9')
            return 0;
        rows = rows * 10 + (buffer[i] - '0');
		i++;
    }
    if (rows <= 0)
        return 0;

    int current_row;
	current_row = 0;
    int current_col;
	current_col = 0;
    int expected_cols;
	expected_cols = -1;
    int i;
	i = newline_idx + 1;

    while (i < size)
	{
        if (buffer[i] == '\n')
		{
            if (expected_cols == -1)
			{
                expected_cols = current_col;
            }
			else if (current_col != expected_cols)
			{
                return 0;
            }
            current_row++;
            current_col = 0;
            i++;
            continue;
        }
        if (buffer[i] != empty && buffer[i] != obs)
            return 0;
        current_col++;
        i++;
    }

    if (current_row != rows)
        return 0;
    if (expected_cols <= 0)
        return 0;

    map->rows = rows;
    map->cols = expected_cols;
    map->empty = empty;
    map->obs = obs;
    map->full = full;
    map->buffer = buffer;
    map->buffer_size = size;
    map->first_line_len = newline_idx;

    return 1;
}
