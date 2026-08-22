#include "rush-02.h"

static void	append_dict_entry(t_dict **dict, int *size, unsigned long long key, char *value)
{
	t_dict	*new_arr;
	int		i;

	new_arr = malloc(sizeof(t_dict) * (*size + 1));
	if (!new_arr)
		return ;
	i = 0;
	while (i < *size)
	{
		new_arr[i] = (*dict)[i];
		i++;
	}
	new_arr[*size].key = key;
	new_arr[*size].value = ft_strdup(value);
	if (!new_arr[*size].value)
	{
		free(new_arr);
		return ;
	}
	free(*dict);
	*dict = new_arr;
	(*size)++;
}

static int	process_line(char *line, t_dict **dict, int *size)
{
	char	*sep;
	char	*key_str;
	char	*val_str;
	unsigned long long	key;
	int		i;

	if (!line || *line == '\0')
		return (1);
	sep = line;
	while (*sep && *sep != ':')
		sep++;
	if (*sep != ':')
		return (0);
	*sep = '\0';
	key_str = ft_strtrim(line);
	val_str = ft_strtrim(sep + 1);
	if (!key_str || !*key_str || !val_str || !*val_str)
		return (0);
	i = 0;
	while (key_str[i])
	{
		if (!ft_isdigit(key_str[i]))
			return (0);
		i++;
	}
	key = 0;
	i = 0;
	while (key_str[i])
	{
		key = key * 10 + (key_str[i] - '0');
		i++;
	}
	append_dict_entry(dict, size, key, val_str);
	return (1);
}

static int	read_dict_file(const char *filename, t_dict **dict, int *size)
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	char	line[BUFFER_SIZE];
	int		line_len;
	ssize_t	bytes;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line_len = 0;
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = 0;
		while (i < bytes)
		{
			if (buf[i] == '\n')
			{
				line[line_len] = '\0';
				if (!process_line(line, dict, size))
				{
					close(fd);
					return (0);
				}
				line_len = 0;
			}
			else
			{
				if (line_len < BUFFER_SIZE - 1)
					line[line_len++] = buf[i];
				else
				{
					close(fd);
					return (0);
				}
			}
			i++;
		}
	}
	if (line_len > 0)
	{
		line[line_len] = '\0';
		if (!process_line(line, dict, size))
			return (0);
	}
	close(fd);
	return (1);
}

static void	sort_dict(t_dict *dict, int size)
{
	int	i, j;
	t_dict	tmp;

	i = 1;
	while (i < size)
	{
		tmp = dict[i];
		j = i - 1;
		while (j >= 0 && dict[j].key > tmp.key)
		{
			dict[j + 1] = dict[j];
			j--;
		}
		dict[j + 1] = tmp;
		i++;
	}
}

static int	check_duplicates(t_dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (dict[i].key == dict[i + 1].key)
			return (0);
		i++;
	}
	return (1);
}

static int	check_required_keys(t_dict *dict, int size)
{
	unsigned long long required[] = {
		0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
		30,40,50,60,70,80,90,100,1000,1000000,1000000000
	};
	int	num_req = sizeof(required) / sizeof(required[0]);
	int	i, j, found;

	j = 0;
	while (j < num_req)
	{
		found = 0;
		i = 0;
		while (i < size)
		{
			if (dict[i].key == required[j])
			{
				found = 1;
				break;
			}
			i++;
		}
		if (!found)
			return (0);
		j++;
	}
	return (1);
}

t_dict	*parse_dict(const char *filename, int *size)
{
	t_dict	*dict;

	*size = 0;
	dict = NULL;
	if (!read_dict_file(filename, &dict, size))
	{
		free_dict(dict, *size);
		return (NULL);
	}
	if (*size == 0)
		return (NULL);
	sort_dict(dict, *size);
	if (!check_duplicates(dict, *size))
	{
		free_dict(dict, *size);
		return (NULL);
	}
	if (!check_required_keys(dict, *size))
	{
		free_dict(dict, *size);
		return (NULL);
	}
	return (dict);
}

void	free_dict(t_dict *dict, int size)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (i < size)
	{
		free(dict[i].value);
		i++;
	}
	free(dict);
}

char	*lookup_value(t_dict *dict, int size, unsigned long long key)
{
	int	low = 0, high = size - 1, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (dict[mid].key == key)
			return (dict[mid].value);
		else if (dict[mid].key < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (NULL);
}
