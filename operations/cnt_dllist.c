#include "../push_swap.h"

int	cnt_dllist(t_stuck *stuck)
{
	int	cnt;
    t_node *node;

    node = stuck->top;
	if (node == NULL)
		return (0);
	cnt = 1;
	while (node->next != stuck->top)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}