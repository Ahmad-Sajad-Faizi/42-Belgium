#include "rush.h"
#include <stdlib.h>

static int	ft_atoi(const char *s)
{
	int	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	int	x, y;
	int	version = 0;

	if (argc < 3 || argc > 4)
		return (0);

	if (argc == 4)
	{
		version = ft_atoi(argv[1]);
		x = ft_atoi(argv[2]);
		y = ft_atoi(argv[3]);
	}
	else
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
	}

	if (x <= 0 || y <= 0)
		return (0);

	if (version == 0)
		rush00(x, y);
	else if (version == 1)
		rush01(x, y);
	else if (version == 2)
		rush02(x, y);
	else if (version == 3)
		rush03(x, y);
	else if (version == 4)
		rush04(x, y);

	return (0);
}
