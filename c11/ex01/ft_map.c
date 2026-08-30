#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*new;
	int	i;

	new = malloc(sizeof(int) * length);
	if (!new)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new[i] = f(tab[i]);
		i++;
	}
	return (new);
}
