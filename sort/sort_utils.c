/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:29:39 by mai               #+#    #+#             */
/*   Updated: 2021/12/15 15:17:00 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// スタックの内容がソート済みになっているか
bool	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next != stack->top)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

// 最小値の検索
int	get_min_index(t_stack *stack)
{
	int		i;
	int		min_value;
	int		min_index;
	t_node	*node;

	i = 1;
	min_index = 0;
	min_value = stack->top->value;
	node = stack->top->next;
	while (node != stack->top)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_index = i;
		}
		i++;
		node = node->next;
	}
	return (min_index);
}

// 
void	rotate_multi(t_stack *stack, int num, void (*rotate)(t_stack *))
{
	while (num)
	{
		rotate(stack);
		num--;
	}
}

//
void	print_stack(t_stack *stack)
{
	t_node	*node;
	int		len;

	len = cnt_dllist(stack);
	node = stack->top;
	if (!node)
		return ;
	printf("======start print stack======\n");
	while (len--)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n======end print stack======\n");
}

int med3(int a, int b, int c)
{
    if (a < b)
        if (b < c)       // a < b < c
            return b;
        else if (a < c)  // a < c <= b
            return c;
        else             // c <= a < b
            return a;
    else
        if (a < c)       // b <= a < c
            return a;
        else if (b < c)  // b < c <= a
            return c;
        else             // c <= b < a
            return b;
}

// スタックからピボットとする値を選択する
// 3つの値を選んで、それらのうちの真ん中の値をpivotにする
int	choice_pivot(t_stack *stack)
{
	int	pivot;
	
	pivot = med3(stack->top->value, stack->top->next->value, stack->bottom->value);
	return (pivot);
}

// スタックaの値をa(大)とb(小)に分割
// ピボットは小に分類する
// 初回のみ
void	split_a_stack(t_stack *a, t_stack *b, int len)
{
	int		pivot;
	t_node	*node;

	pivot = choice_pivot(a);
	// len--;
	while (len)
	{
		// printf("a->top->value:%d\n", a->top->value);
		if (pivot >= a->top->value)
			push_b(a, b);
		else
			rotate_a(a);
		len--;
	}
}

// スタックbの値をa(大)とb(小)に分割
// 分割後のbの長さを返す
void	split_b_stack(t_stack *a, t_stack *b)
{
	int		pivot;
	t_node	*node;
	int		len;

	pivot = choice_pivot(b);
	// len = cnt_dllist(b) - 1;
	// rotate_b(b);
	// while (len)
	// {
	if (pivot <= b->top->value)
		push_a(a, b);
	else
		rotate_b(b);
		// len--;
	// }
}

// スタックの内容が分割可能か
bool	is_splittable(t_stack *stack)
{
	int	cnt;

	cnt = cnt_dllist(stack);
	if (cnt <= 6)
		return (false);
	return (true);
}

// aの末尾にbの値を小さい順に追加する
// bはソート済み
// 追加した値の個数を返す
void	add_min_values(t_stack *a, t_stack *b, int b_len)
{
	while (b_len--)
	{
		push_a(a, b);
		rotate_a(a);
	}
}

// ソート済み以外の値をbにpushする
void	push_without_sorted(t_stack *a, t_stack *b, int len, int sorted_len)
{
	while (len > sorted_len)
	{
		push_b(a, b);
		len--;
	}

	// printf("++a(push_without_sorted)++\n");
	// print_stack(a);
	// printf("++b(push_without_sorted)++\n");
	// print_stack(b);
}
