#include "rush-02.h"

static int	is_scale_key(unsigned long long key)
{
	return (key == 100 || key == 1000 || key == 1000000 || key == 1000000000);
}

static unsigned long long	find_largest_key_le(t_dict *dict, int size, unsigned long long n)
{
	int	low = 0, high = size - 1, mid;
	unsigned long long	best = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (dict[mid].key <= n)
		{
			best = dict[mid].key;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return (best);
}

char	*convert_number(unsigned long long n, t_dict *dict, int size)
{
	char	*value;
	char	*result;
	char	*tmp;
	char	*part;
	unsigned long long	key;
	unsigned long long	quot;
	unsigned long long	rem;

	if (n == 0)
		return (ft_strdup(lookup_value(dict, size, 0)));

	key = find_largest_key_le(dict, size, n);
	if (key == 0)
		return (NULL);

	value = lookup_value(dict, size, key);
	if (!value)
		return (NULL);

	if (key == n && !is_scale_key(key))
		return (ft_strdup(value));

	quot = n / key;
	rem = n % key;

	if (is_scale_key(key))
	{
		part = convert_number(quot, dict, size);
		if (!part)
			return (NULL);
		result = ft_strjoin(part, " ");
		free(part);
		if (!result)
			return (NULL);
		tmp = ft_strjoin(result, value);
		free(result);
		if (!tmp)
			return (NULL);
		result = tmp;
		if (rem > 0)
		{
			part = convert_number(rem, dict, size);
			if (!part)
			{
				free(result);
				return (NULL);
			}
			tmp = ft_strjoin(result, " ");
			free(result);
			if (!tmp)
			{
				free(part);
				return (NULL);
			}
			result = tmp;
			tmp = ft_strjoin(result, part);
			free(result);
			free(part);
			if (!tmp)
				return (NULL);
			result = tmp;
		}
		return (result);
	}
	else
	{
		if (rem == 0)
			return (ft_strdup(value));
		part = convert_number(rem, dict, size);
		if (!part)
			return (NULL);
		result = ft_strjoin(value, " ");
		if (!result)
		{
			free(part);
			return (NULL);
		}
		tmp = ft_strjoin(result, part);
		free(result);
		free(part);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
}
