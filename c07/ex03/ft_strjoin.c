#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int	total_len;
	int	i;
	int	sep_len;
	int	pos;

	if (size == 0)
	{
		result = malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	sep_len = ft_strlen(sep);
	total_len += sep_len * (size - 1);
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < size)
	{
		ft_strcpy(result + pos, strs[i]);
		pos += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(result + pos, sep);
			pos += sep_len;
		}
		i++;
	}
	result[pos] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	char *strs[] = {"Hello", "42", "Piscine", "C07"};
	char *sep = " - ";
	char *result;

	result = ft_strjoin(4, strs, sep);
	printf("Result: '%s' (Expected: 'Hello - 42 - Piscine - C07')\n", result);
	if (result)
		free(result);
        printf("\nTesting size 0:\n");
	result = ft_strjoin(0, strs, sep);
	printf("Result: '%s' (Expected: '')\n", result);
	if (result)
		free(result);
	return (0);
}*/
