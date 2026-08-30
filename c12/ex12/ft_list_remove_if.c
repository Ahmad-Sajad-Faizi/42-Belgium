#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*prev;
	t_list	*tmp;

	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		if (cmp(curr->data, data_ref) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*begin_list = curr->next;
			if (free_fct)
				free_fct(curr->data);
			tmp = curr;
			curr = curr->next;
			free(tmp);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
