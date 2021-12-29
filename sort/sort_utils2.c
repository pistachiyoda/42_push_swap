/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:58:17 by fmai              #+#    #+#             */
/*   Updated: 2021/12/29 22:33:08 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// スタックaの値をa(大)とb(小)に分割
// ピボットはb(小)に分類する
// 初回のみ
void	split_a_stack(
	t_stack *a, t_stack *b, int len, t_stack *unsorted_nums_list)
{
	int		pivot;
	int		*nums;

	nums = sort_nums(a);
	pivot = choice_pivot(nums, len);
	while (len)
	{
		if (pivot >= a->top->value)
			push_b(a, b);
		else
			rotate_a(a);
		len--;
	}
	push_chunk(unsorted_nums_list, cnt_dllist(a));
	free(nums);
}

// スタックbの値をa(大)とb(小)に分割
// ピボットはb(小)に分類する
void	split_b_stack(t_stack *a, t_stack *b, t_stack *unsorted_list)
{
	int		pivot;
	int		len;
	int		*nums;

	len = cnt_dllist(b);
	nums = sort_nums(b);
	pivot = choice_pivot(nums, len);
	push_chunk(unsorted_list, 0);
	while (len)
	{
		if (b->top->value == nums[0])
		{
			push_a(a, b);
			rotate_a(a);
		}
		else if (pivot <= b->top->value)
		{
			push_a(a, b);
			unsorted_list->top->value += 1;
		}
		else
			rotate_b(b);
		len--;
	}
	free(nums);
}

// スタックの内容が分割可能（７以上）ならtrue, なっていなかったらfalseを返す
bool	is_splittable(t_stack *stack)
{
	int	cnt;

	cnt = cnt_dllist(stack);
	if (cnt >= 7)
		return (true);
	return (false);
}

// スタックbの値をaの末尾に追加する
void	add_min_values(t_stack *a, t_stack *b, int b_len)
{
	while (b_len --)
	{
		push_a(a, b);
		rotate_a(a);
	}
}
