#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define DICT_DEFAULT "numbers.dict"
# define BUFFER_SIZE 4096

typedef struct s_dict
{
	unsigned long long	key;
	char				*value;
}	t_dict;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
int			ft_isspace(int c);
char		*ft_strtrim(char *s);

t_dict		*parse_dict(const char *filename, int *size);
void		free_dict(t_dict *dict, int size);
char		*lookup_value(t_dict *dict, int size, unsigned long long key);
int			validate_dict(t_dict *dict, int size);

char		*convert_number(unsigned long long n, t_dict *dict, int size);

#endif
