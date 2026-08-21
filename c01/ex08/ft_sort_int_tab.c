void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int min_index;
	int tmp;

	i = 0;
	while(i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min_index])
					min_index = j;
			j++;
		}
		if (min_index != i)
		{
			l = tab[i];
			tab[i] = tab[min_index];
			tab[min_index] = l;
		}
		i++;
	}
}

#include <stdio.h>
int	main(void)
{
	int arr[] = {5, 2, 8, 1, 9, 3};
    int size = 6;
    int i;

    printf("Before: ");
    i = 0;
	while(i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

    ft_sort_int_tab(arr, size);

    printf("After:  ");
    i = 0;
	while(i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

    return (0);
}
