#include "ft_list.h"

static int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

static t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list && nbr--)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		len;
	int		i;
	t_list	*left;
	t_list	*right;
	void	*tmp;

	len = ft_list_size(begin_list);
	i = 0;
	while (i < len / 2)
	{
		left = ft_list_at(begin_list, i);
		right = ft_list_at(begin_list, len - 1 - i);
		tmp = left->data;
		left->data = right->data;
		right->data = tmp;
		i++;
	}
}
