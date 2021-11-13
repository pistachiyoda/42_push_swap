#include "../push_swap.h"

void    sort_less_than_six_values_a(t_stack *stack)
{

}

void    sort_three_values(
    t_stack *stack, void (* swap)(t_stack *),
    void (* rotate)(t_stack *), void (* rev_rotate)(t_stack *)
)
{
    t_node *first;
    t_node *second;
    t_node *third;

    first = stack->top;
    second = stack->top->next;
    third = stack->bottom;
    if (first->value > second->value && second->value < third->value && third->value > first->value)
        return swap(stack);
    if (first->value > second->value && second->value > third->value && third->value < first->value)
    {
        swap(stack);
        return rev_rotate(stack);
    }
    if (first->value > second->value && second->value < third->value && third->value < first->value)
        return rotate(stack);
    if (first->value < second->value && second->value > third->value && third->value > first->value)
    {
        swap(stack);
        return rotate(stack);
    }
    return rev_rotate_a(stack);
}

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
// 分割後のbの長さを返す
int    split_b_stack(t_stack *a, t_stack *b)
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
    return (cnt_dllist(b));
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
    int b_len;
    int sorted_len;

    if (is_sorted(a))
        return;
    len = cnt_dllist(a);
    if (len == 3)
        return sort_three_values(a, swap_a, rotate_a, rev_rotate_a);
    sorted_len = 0;
    split_a_stack(a, b, len);
    b_len = cnt_dllist(b);
    while (len != sorted_len)
    {
        while (is_splittable(b))
        {
            b_len = split_b_stack(a, b);
            if (b_len == 3)
            {
                sort_three_values(b, swap_b, rotate_b, rev_rotate_b);
                break;
            }
            rotate_b(b);
        }
        sorted_len += add_min_values(a, b);
        push_without_sorted(a, b, len, sorted_len);
    }

}