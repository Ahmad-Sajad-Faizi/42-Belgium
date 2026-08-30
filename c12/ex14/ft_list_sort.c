#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;
	t_list	*next;
	void	*tmp;
	int		swapped;

	if (!begin_list || !*begin_list)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		curr = *begin_list;
		while (curr && curr->next)
		{
			next = curr->next;
			if (cmp(curr->data, next->data) > 0)
			{
				tmp = curr->data;
				curr->data = next->data;
				next->data = tmp;
				swapped = 1;
			}
			curr = curr->next;
		}
	}
}
