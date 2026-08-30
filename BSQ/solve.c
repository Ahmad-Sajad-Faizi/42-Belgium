#include "bsq.h"

void solve_map(t_map *map)
{
    int *dp;
	dp = malloc(map->cols * sizeof(int));
    if (!dp)
	{
        ft_puterror();
        return;
    }
    int i;
	i = 0;
    while (i < map->cols)
	{
        dp[i] = 0;
        i++;
    }
    int max_size;
	max_size = 0;
    int max_r;
	max_r = 0;
    int max_c;
	max_c = 0;
    int map_start;
	map_stat = map->first_line_len + 1;

    int r;
	r = 0;
    while (r < map->rows)
	{
        int prev;
		prev = 0;
        int c;
		c = 0;
        while (c < map->cols)
		{
            int temp;
			temp = dp[c];
            int idx;
			idx = map_start + r * (map->cols + 1) + c;

            if (map->buffer[idx] == map->obs)
			{
                dp[c] = 0;
            }
			else
			{
                if (r == 0 || c == 0)
				{
                    dp[c] = 1;
                }
				else
				{
                    int min;
					min = dp[c];
                    if (dp[c - 1] < min)
                        min = dp[c - 1];
                    if (prev < min)
                        min = prev;
                    dp[c] = 1 + min;
                }
                if (dp[c] > max_size)
				{
                    max_size = dp[c];
                    max_r = r;
                    max_c = c;
                }
            }
            prev = temp;
            c++;
        }
        r++;
    }
    free(dp);
    if (max_size > 0)
	{
        r = max_r - max_size + 1;
        while (r <= max_r)
		{
            int c;
			c = max_c - max_size + 1;
            while (c <= max_c)
			{
                int idx;
				idx = map_start + r * (map->cols + 1) + c;
                map->buffer[idx] = map->full;
                c++;
            }
            r++;
        }
    }

    write(1, map->buffer, map->buffer_size);
}
