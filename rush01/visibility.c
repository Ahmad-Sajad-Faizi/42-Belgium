#include "rush01.h"

int	count_visible(int *arr, int n)
{
	int	max = 0;
	int	count = 0;
	int	i = 0;
	while (i < n)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			count++;
		}
		i++;
	}
	return (count);
}
