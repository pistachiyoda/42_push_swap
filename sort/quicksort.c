#include "../push_swap.h"

void    print_stack(t_stack *stack)
{
    t_node *node;

    node = stack->top;
    node = node->next;
    while (node != stack->top)
    {
        node = node->next;
    }
}

// スタックからピボットとする値を選択する
int    choice_pivot(t_stack *stack)
{
    int pivot;

    pivot = stack->top->value;
    return (pivot);
}

// スタックaの値をa(大)とb(小)に分割
// 初回のみ
void    split_a_stack(t_stack *a, t_stack *b, int len)
{
    int pivot;
    t_node  *node;

    pivot = choice_pivot(a);
    push_b(a, b);
    len--;
    while (len)
    {
        if (pivot > a->top->value)
            push_b(a, b);
        else
            rotate_a(a);
        len--;
    }

}

// スタックbの値をa(大)とb(小)に分割
void    split_b_stack(t_stack *a, t_stack *b)
{
    int pivot;
    t_node  *node;
    int len;

    pivot = choice_pivot(b);
    len = cnt_dllist(b) - 1;
    rotate_b(b);
    while (len)
    {
        if (pivot < b->top->value)
            push_a(a, b);
        else
            rotate_b(b);
        len--;
    }
}

// スタックの内容がソート済みになっているか
bool    is_sorted(t_stack *stack)
{
    t_node *node;

    node = stack->top;
    while(node->next != stack->top)
    {
        if (node->value > node->next->value)
            return (false);
        node = node->next;
    }
    return (true);
}

// スタックの内容が分割可能か
bool    is_splittable(t_stack *stack)
{
    int cnt;

    cnt = cnt_dllist(stack);
    if (cnt <= 2)
        return (false);
    return (true);
}

// aの末尾にbの値を小さい順に追加する
// 追加した値の個数を返す
int    add_min_values(t_stack *a, t_stack *b)
{
    if (b->top == b->bottom)
    {
        push_a(a, b);
        rotate_a(a);
        return (1);
    }
    if (b->top->value < b->bottom->value)
        rotate_b(b);
    push_a(a, b);
    push_a(a, b);
    rotate_a(a);
    rotate_a(a);
    return (2);
}

// ソート済み以外の値をbにpushする
void    push_without_sorted(t_stack *a, t_stack *b, int len, int sorted_len)
{
    while (len > sorted_len)
    {
        push_b(a, b);
        len--;
    }
}

void    quicksort(t_stack *a, t_stack *b)
{
    int len;
    int sorted_len;

    if (is_sorted(a))
        return;
    len = cnt_dllist(a);
    sorted_len = 0;
    split_a_stack(a, b, len);
    while (len != sorted_len)
    {
        while (is_splittable(b))
        {
            split_b_stack(a, b);
            rotate_b(b);
        }
        sorted_len += add_min_values(a, b);
        push_without_sorted(a, b, len, sorted_len);
    }
}