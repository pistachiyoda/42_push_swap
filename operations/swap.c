#include "../push_swap.h"

void    swap_top(t_stuck *stuck)
{
    t_node *top_to_second;
    t_node *second_to_top;
    t_node *third;
    t_node *bottom;
    int stuck_size;

    stuck_size = cnt_dllist(stuck);
    if (stuck_size <= 1)
        return ;
    if (stuck_size == 2)
    {
        top_to_second = stuck->top;
        stuck->top = stuck->bottom;
        stuck->bottom = top_to_second;
        return;
    }

    top_to_second = stuck->top;
    second_to_top = top_to_second->next;
    third = second_to_top->next;

    second_to_top->prev = stuck->bottom;
    second_to_top->next = top_to_second;

    top_to_second->prev = second_to_top;
    top_to_second->next = third;

    third->prev = top_to_second;

    bottom = stuck->bottom;
    bottom->next = second_to_top;

    stuck->top = second_to_top;
}

void    swap_a(t_stuck *a)
{
    swap_top(a);
    ft_putstr_fd("sa\n", 0);
}

void    swap_b(t_stuck *b)
{
    swap_top(b);
    ft_putstr_fd("sb\n", 0);
}

void    swap_s(t_stuck *a, t_stuck *b)
{
    swap_top(a);
    swap_top(b);
    ft_putstr_fd("ss\n", 0);
}