/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:29:39 by mai               #+#    #+#             */
/*   Updated: 2021/12/17 13:54:59 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// スタックの内容がソート済みになっていたらtrue, なっていなかったらfalseを返す
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

// スタックの値から最小値の検索し、返す
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

// スタックの値を表示、確認用、後で消す！！！！！！！
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

// 3つの値のうち、真ん中の値を返す
int get_med_of_3vals(int a, int b, int c)
{
    if (a < b)
        if (b < c)
            return b;
        else if (a < c)
            return c;
        else
            return a;
    else
        if (a < c)
            return a;
        else if (b < c)
            return c;
        else
            return b;
}

// 5つの値のうち、真ん中の値を返す
int get_med_of_7vals(int *nums)
{
	int i;
	int j;
	int k;
	int min;
	int tmp;

	i = 0;
	while (i < 7)
	{
		min = nums[i]; 
		k = i;
		j = i + 1;
		while (j < 7)
		{
			if (nums[j] < min)
			{
				min = nums[j];
				k = j;
				tmp = nums[i];
				nums[i] = nums[k];
				nums[k] = tmp;
			}
			j++;
		}
		i++;
	}
    return (nums[3]);
}

// スタックからピボットとする値を選択する
// 5つの値を選んで、それらのうちの真ん中の値をpivotにする
int	choice_pivot(t_stack *stack)
{
	int nums[7];
	
	nums[0] = stack->top->value;
	nums[1] = stack->top->next->value;
	nums[2] = stack->top->next->next->value;
	nums[3] = stack->top->next->next->next->value;
	nums[4] = stack->bottom->value;
	nums[5] = stack->bottom->prev->value;
	nums[6] = stack->bottom->prev->prev->value;

	return (get_med_of_7vals(nums));
}

// スタックaの値をa(大)とb(小)に分割
// ピボットはb(小)に分類する
// 初回のみ
void	split_a_stack(t_stack *a, t_stack *b, int len)
{
	int		pivot;
	t_node	*node;

	pivot = choice_pivot(a);
	while (len)
	{
		if (pivot >= a->top->value)
			push_b(a, b);
		else
			rotate_a(a);
		len--;
	}
}

// スタックbの値をa(大)とb(小)に分割
// ピボットはb(小)に分類する
void	split_b_stack(t_stack *a, t_stack *b)
{
	int		pivot;
	t_node	*node;
	int		len;

	pivot = choice_pivot(b);
	len = cnt_dllist(b);
	while (len)
	{
		if (pivot <= b->top->value)
			push_a(a, b);
		else
			rotate_b(b);
		len--;
	}
}

// スタックの内容が分割可能（７以上）ならtrue, なっていなかったらfalseを返す
bool	is_splittable(t_stack *stack)
{
	int	cnt;

	cnt = cnt_dllist(stack);
	if (cnt <= 6)
		return (false);
	return (true);
}

// スタックbの値をaの末尾に追加する
void	add_min_values(t_stack *a, t_stack *b, int b_len)
{
	while (b_len--)
	{
		push_a(a, b);
		rotate_a(a);
	}
}

// ソートされていないスタックaにある値をsスタックbに移動する
void	push_without_sorted(t_stack *a, t_stack *b, int len, int sorted_len)
{
	while (len > sorted_len)
	{
		push_b(a, b);
		len--;
	}
}
