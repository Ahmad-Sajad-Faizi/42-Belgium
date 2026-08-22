#include "rush-02.h"

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len = ft_strlen(s) + 1;
	char	*dup = malloc(len);
	if (!dup)
		return (NULL);
	size_t	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (NULL);
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);
	char	*res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	size_t	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	size_t	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r');
}

char	*ft_strtrim(char *s)
{
	char	*start = s;
	while (*start && ft_isspace(*start))
		start++;
	char	*end = start + ft_strlen(start) - 1;
	while (end > start && ft_isspace(*end))
		end--;
	*(end + 1) = '\0';
	return (start);
}
