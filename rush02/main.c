#include "rush-02.h"

static unsigned long long	parse_number(const char *str, int *valid)
{
	unsigned long long	n = 0;

	*valid = 1;
	if (!str || !*str)
	{
		*valid = 0;
		return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			*valid = 0;
			return (0);
		}
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

static void	print_error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
}

int	main(int argc, char **argv)
{
	const char	*dict_file;
	const char	*num_str;
	unsigned long long	number;
	int			valid;
	t_dict		*dict;
	int			size;
	char		*result;

	if (argc < 2 || argc > 3)
		return (1);

	if (argc == 2)
	{
		dict_file = DICT_DEFAULT;
		num_str = argv[1];
	}
	else
	{
		dict_file = argv[1];
		num_str = argv[2];
	}

	number = parse_number(num_str, &valid);
	if (!valid)
	{
		print_error("Error\n");
		return (1);
	}

	dict = parse_dict(dict_file, &size);
	if (!dict)
	{
		print_error("Dict Error\n");
		return (1);
	}

	result = convert_number(number, dict, size);
	if (!result)
	{
		print_error("Dict Error\n");
		free_dict(dict, size);
		return (1);
	}

	write(1, result, ft_strlen(result));
	write(1, "\n", 1);

	free(result);
	free_dict(dict, size);
	return (0);
}
