#include "../push_swap.h"

// node①のnextをnode②にし、node②のprevをnode①にする
void    connect_nodes(t_node *node_1, t_node *node_2)
{
    node_1->next = node_2;
    node_2->prev = node_1;
}

t_node  *handle_from(t_stuck *stuck)
{
    int     cnt_list;
    t_node  *top;

    cnt_list = cnt_dllist(stuck);
    if (cnt_list == 0)
        return (NULL);
    top = stuck->top;
    if (cnt_list == 1)
    {
        stuck->bottom = NULL;
        stuck->top = NULL;
    }
    else
    {
        connect_nodes(stuck->bottom, stuck->top->next);
        stuck->top = stuck->bottom->next;
    }
    return (top);
}

void    handle_to(t_stuck *stuck, t_node *node)
{
    int     cnt_list;

    if (node == NULL)
        return;
    cnt_list = cnt_dllist(stuck);
    stuck->top = node;
    if (cnt_list == 0)
    {
        stuck->bottom = node;
        connect_nodes(node, node);
        return;
    }
    connect_nodes(node, stuck->bottom->next);
    connect_nodes(stuck->bottom, node);
    stuck->top = node;
}

void    push(t_stuck *to, t_stuck *from)
{
    t_node  *node;

    node = handle_from(from);
    handle_to(to, node);
}

// take the first element at the top of b and put it at the top of a. Do nothing if b is empty
void    push_a(t_stuck *a, t_stuck *b)
{
    if (b == NULL)
        return ;
    push(a, b);
    ft_putstr_fd("pa\n", 0);
}

// take the first element at the top of a and put it at the top of b. Do nothing if a is empty
void    push_b(t_stuck *a, t_stuck *b)
{
    if (a ==NULL)
        return ;
    push(b, a);
    ft_putstr_fd("pb\n", 0);
}
