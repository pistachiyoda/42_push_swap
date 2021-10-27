#include "push_swap.h"
int main(int argc, char **argv)
{
    t_node *node;
    node = create_nodes(argc - 1, argv);
    while (1)
    {
        printf("node:%p\n", node);
        printf("node->value:%d\n", node->value);
        printf("==============================\n");
        printf("node->next:%p\n", node->next);
        if (node->next == NULL)
            break;
        node = node->next;
    }
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    while (1)
    {
        printf("node:%p\n", node);
        printf("node->value:%d\n", node->value);
        printf("==============================\n");
        printf("node->prev:%p\n", node->prev);
        if (node->prev == NULL)
            break;
        node = node->prev;
    }
    return (0);
}