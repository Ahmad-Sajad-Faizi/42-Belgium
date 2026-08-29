#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
/*
#include <stdio.h>
int	main(void)
{
	int *range;
	int min = 5;
	int max = 10;
	int size;
	int i = 0;

	size = ft_ultimate_range(&range, min, max);
	if (range != NULL)
	{
		printf("array contents: ");
		while (i < size)
		{
			printf("%d ", range[i]);
			i++;
		}
		printf("\n");
		free(range);
	}
	return (0);
}
*/
