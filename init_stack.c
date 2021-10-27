#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void    append_node(t_node *first_node, t_node *new_node)
{
    t_node  *current_node = first_node;

    while (current_node->next)
        current_node = current_node->next;
    current_node->next = new_node;
    new_node->prev = current_node;
}

t_node    *create_nodes(int num, char **num_list)
{
    int value;
    int cnt;
    t_node *node;
    t_node *first_node;

    cnt = 0;
    num_list++;
    while(num > cnt)
    {
        value = ft_atoi(*num_list);
        node = create_node(value);
        if (cnt == 0)
            first_node = node;
        else
            append_node(first_node, node);
        num_list++;
        cnt++;
    }
    return (first_node);
}
