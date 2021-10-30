#include "../push_swap.h"

// node①のnextをnode②にし、node②のprevをnode①にする
void    connect_nodes(t_node *node_1, t_node *node_2)
{
    node_1->next = node_2;
    node_2->prev = node_1;
}

void    push(t_stuck *x, t_stuck *y)
{
    t_node  *y_second;

    if (y == NULL)
        return;

    y_second = y->top->next;
    
    // yのbottomのnextをyのsecond(y->top->next)に変更
    // yのsecondのprevをyのbottomのnextに変更
    connect_nodes(y->bottom, y_second);
    
    // xのbottomのnextをyのtopに変更
    // yのtopのprevをxのbottomに変更
    connect_nodes(x->bottom, y->top);

    // yのtopのnextをxのtopに変更
    // xのtopのprevをyのtopに変更
    connect_nodes(y->top, x->top); // ここでy_topのnextが変わる

    // xのtop変更
    x->top =y->top;
    
    // yのtopを変更
    y->top = y_second;
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
