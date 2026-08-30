int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	if (length <= 1)
		return (1);
	asc = 1;
	desc = 1;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			asc = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			desc = 0;
		i++;
	}
	return (asc || desc);
}
