#include "../push_swap.h"

void    swap_a(t_stuck *a)
{
    t_node *top_to_second;
    t_node *second_to_top;
    t_node *third;
    t_node *bottom;

    top_to_second = a->top;
    second_to_top = top_to_second->next;
    third = second_to_top->next;

    second_to_top->prev = a->bottom;
    second_to_top->next = top_to_second;

    top_to_second->prev = second_to_top;
    top_to_second->next = third;

    bottom = a->bottom;
    bottom->next = second_to_top;

    a->top = second_to_top;
    ft_putstr_fd("sa\n", 0);
}

void    swap_b(t_stuck *b)
{
    t_node *top_to_second;
    t_node *second_to_top;
    t_node *third;
    t_node *bottom;

    top_to_second = b->top;
    second_to_top = top_to_second->next;
    third = second_to_top->next;

    second_to_top->prev = b->bottom;
    second_to_top->next = top_to_second;

    top_to_second->prev = second_to_top;
    top_to_second->next = third;

    bottom = b->bottom;
    bottom->next = second_to_top;

    b->top = second_to_top;
    ft_putstr_fd("sb\n", 0);
}

void    swap_sametime(t_stuck *a, t_stuck *b)
{
    swap_a(a);
    swap_b(b);
    ft_putstr_fd("ss\n", 0);
}