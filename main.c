#include "push_swap.h"
int main(int argc, char **argv)
{
    t_node *node;
    t_stuck *stuck_a;

    stuck_a = (t_stuck *)malloc(sizeof(t_stuck));
    create_nodes(argc - 1, argv, stuck_a);
    swap_b(stuck_a);
    node = stuck_a->top;
    int n = 10;
    while (n--)
    {
        printf("node:%p\n", node);
        printf("node->value:%d\n", node->value);
        printf("node->prev:%p\n", node->prev);
        printf("node->next:%p\n", node->next);
        printf("==============================\n");
        node = node->next;
    }
    return (0);
}