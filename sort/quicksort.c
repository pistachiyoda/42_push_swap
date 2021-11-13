#include "../push_swap.h"

void    sort_less_than_six_values_a(t_stack *stack)
{

}

void    sort_two_values(t_stack *stack, void (*swap)(t_stack *))
{
    if (stack->top->value < stack->bottom->value)
        return;
    swap(stack);
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
    int len;

    len = cnt_dllist(stack);
    node = stack->top;
    if (!node)
        return;
    printf("======start print stack======\n");
    while (len--)
    {
        printf("%d\n", node->value);
        node = node->next;
    }
    printf("======end print stack======\n");
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
    if (cnt <= 3)
        return (false);
    return (true);
}

// aの末尾にbの値を小さい順に追加する
// bはソート済み
// 追加した値の個数を返す
void    add_min_values(t_stack *a, t_stack *b, int b_len)
{
    while (b_len--)
    {
        push_a(a, b);
        rotate_a(a);
    }
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
            split_b_stack(a, b);
            rotate_b(b);
        }
        b_len = cnt_dllist(b);
        if (b_len == 2)
            sort_two_values(b, swap_b);
        else if (b_len == 3)
            sort_three_values(b, swap_b, rotate_b, rev_rotate_b);
        add_min_values(a, b, b_len);
        sorted_len += b_len;
        push_without_sorted(a, b, len, sorted_len);
    }

}