#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*head;
	t_list	*curr1;
	t_list	*curr2;
	t_list	*tail;

	if (!begin_list1)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (!begin_list2)
		return ;
	if (cmp((*begin_list1)->data, begin_list2->data) <= 0)
	{
		head = *begin_list1;
		curr1 = (*begin_list1)->next;
		curr2 = begin_list2;
	}
	else
	{
		head = begin_list2;
		curr1 = *begin_list1;
		curr2 = begin_list2->next;
	}
	tail = head;
	while (curr1 && curr2)
	{
		if (cmp(curr1->data, curr2->data) <= 0)
		{
			tail->next = curr1;
			curr1 = curr1->next;
		}
		else
		{
			tail->next = curr2;
			curr2 = curr2->next;
		}
		tail = tail->next;
	}
	if (curr1)
		tail->next = curr1;
	else
		tail->next = curr2;
	*begin_list1 = head;
}
