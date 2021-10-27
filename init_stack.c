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

void   create_nodes(int num, char **num_list, t_stuck *stuck)
{
    int value;
    int cnt;
    t_node *node;

    cnt = 0;
    num_list++;
    while(num > cnt)
    {
        value = ft_atoi(*num_list);
        node = create_node(value);
        if (cnt == 0)
            stuck->top = node;
        else
            append_node(stuck->top, node);
        num_list++;
        cnt++;
    }
    stuck->bottom = node;
    
    node = stuck->top;
    node->prev = stuck->bottom;

    node = stuck->bottom;
    node->next = stuck->top;
}