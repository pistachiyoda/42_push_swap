#include "push_swap.h"
int main(int argc, char **argv)
{
    t_node *node;
    t_stuck *stuck_a;
    t_stuck *stuck_b;

    stuck_a = (t_stuck *)malloc(sizeof(t_stuck));
    stuck_b = (t_stuck *)malloc(sizeof(t_stuck));
    create_nodes(argc - 1, argv, stuck_a);
    create_nodes(argc - 1, argv, stuck_b);

    rev_rotate_b(stuck_b);

    node = stuck_a->top;
    int n = 10;
    printf("+++stack a+++\n");
    while (n--)
    {
        // printf("node:%p\n", node);
        printf("node->value:%d\n", node->value);
        // printf("node->prev:%p\n", node->prev);
        // printf("node->next:%p\n", node->next);
        // printf("==============================\n");
        node = node->next;
    }
    printf("\n");
    node = stuck_b->top;
    n = 10;
    printf("+++stack b+++\n");
    while (n--)
    {
        // printf("node:%p\n", node);
        printf("node->value:%d\n", node->value);
        // printf("node->prev:%p\n", node->prev);
        // printf("node->next:%p\n", node->next);
        // printf("==============================\n");
        node = node->next;
    }
    return (0);
}