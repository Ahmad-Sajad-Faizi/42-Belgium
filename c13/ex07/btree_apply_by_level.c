#include <stdlib.h>
#include "ft_btree.h"

typedef struct s_queue
{
	t_btree			*node;
	int				level;
	struct s_queue	*next;
}	t_queue;

static void	enqueue(t_queue **head, t_queue **tail, t_btree *node, int level)
{
	t_queue	*elem;

	elem = (t_queue *)malloc(sizeof(t_queue));
	if (!elem)
		return ;
	elem->node = node;
	elem->level = level;
	elem->next = NULL;
	if (!*head)
		*head = elem;
	else
		(*tail)->next = elem;
	*tail = elem;
}

static t_queue	*dequeue(t_queue **head)
{
	t_queue	*elem;

	elem = *head;
	if (elem)
		*head = elem->next;
	return (elem);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first))
{
	t_queue	*head;
	t_queue	*tail;
	t_queue	*current;
	int		prev_level;
	int		is_first;

	if (!root)
		return ;
	head = NULL;
	tail = NULL;
	enqueue(&head, &tail, root, 0);
	prev_level = -1;
	while (head)
	{
		current = dequeue(&head);
		is_first = (current->level != prev_level);
		applyf(current->node->item, current->level, is_first);
		prev_level = current->level;
		if (current->node->left)
			enqueue(&head, &tail, current->node->left, current->level + 1);
		if (current->node->right)
			enqueue(&head, &tail, current->node->right, current->level + 1);
		free(current);
	}
}
