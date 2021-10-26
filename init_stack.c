#include "push_swap.h"

t_node	*create_node(int value, int position)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
    node->position = position;
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

bool    create_nodes(int num, char **num_list)
{
    int position;

    printf("num = %d\n", num);
    position = 0;
    while(num)
    {
        ft_putstr_fd("test", 1);
        printf("num_list = %s\n", *num_list);
        // create_node(*num_list, position);
        position++;
        num_list++;
        num--;
    }
    return (true);
}