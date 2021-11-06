#include "../push_swap.h"

int	cnt_dllist(t_stack *stack)
{
	int	cnt;
    t_node *node;

    node = stack->top;
	if (node == NULL)
		return (0);
	cnt = 1;
	while (node->next != stack->top)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}