#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *node;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_b = (t_stack *)malloc(sizeof(t_stack));
    create_nodes(argc - 1, argv, stack_a);

    quicksort(stack_a, stack_b);
    // print_stack(stack_a);

    // node = stack_a->top;
    // int n = cnt_dllist(stack_a);
    // printf("+++stack a+++\n");
    // while (n--)
    // {
    //     // printf("node:%p\n", node);
    //     printf("node->value:%d\n", node->value);
    //     // printf("node->prev:%p\n", node->prev);
    //     // printf("node->next:%p\n", node->next);
    //     // printf("==============================\n");
    //     node = node->next;
    // }
    // printf("\n");
    // node = stack_b->top;
    
    // n = cnt_dllist(stack_b);
    // printf("+++stack b+++\n");
    // while (n--)
    // {
    //     // printf("node:%p\n", node);
    //     printf("node->value:%d\n", node->value);
    //     // printf("node->prev:%p\n", node->prev);
    //     // printf("node->next:%p\n", node->next);
    //     // printf("==============================\n");
    //     node = node->next;
    // }

    // printf("========stack a========\n");
    // print_stack(stack_a);
    // printf("========stack b========\n");
    // print_stack(stack_b);
    return (0);
}