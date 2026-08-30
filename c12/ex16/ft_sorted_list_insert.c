#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_elem;
	t_list	*curr;
	t_list	*prev;

	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	if (!*begin_list || cmp(data, (*begin_list)->data) <= 0)
	{
		new_elem->next = *begin_list;
		*begin_list = new_elem;
		return ;
	}
	prev = *begin_list;
	curr = (*begin_list)->next;
	while (curr && cmp(data, curr->data) > 0)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = new_elem;
	new_elem->next = curr;
}
