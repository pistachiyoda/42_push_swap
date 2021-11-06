#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *node;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_b = (t_stack *)malloc(sizeof(t_stack));
    create_nodes(argc - 1, argv, stack_a);

    swap_a(stack_a);

    node = stack_a->top;
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
    node = stack_b->top;
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