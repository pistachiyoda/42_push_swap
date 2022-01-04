/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:58:17 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 18:07:57 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Select the median value to be pivot from the stack
int	choice_pivot(int *nums, int cnt)
{
	int	mid;

	if ((cnt % 2) == 0)
		mid = cnt / 2 - 1;
	else
		mid = (cnt + 1) / 2 - 1;
	return (nums[mid]);
}

// Split stack a by pivot, then push smaller value to stack b.
void	split_a_stack(
	t_stack *a, t_stack *b, int len, t_stack *unsorted_nums_list)
{
	int		pivot;
	int		*nums;

	nums = sort_nums(a, b, unsorted_nums_list);
	pivot = choice_pivot(nums, len);
	while (len)
	{
		if (pivot >= a->top->value)
			push_b(a, b);
		else
			rotate_a(a);
		len--;
	}
	push_chunk(a, b, unsorted_nums_list, cnt_dllist(a));
	free(nums);
}

// Split stack b by pivot, then push bigger value to stack a.
void	split_b_stack(t_stack *a, t_stack *b, t_stack *unsorted_list)
{
	int		pivot;
	int		len;
	int		*nums;

	len = cnt_dllist(b);
	nums = sort_nums(b, a, unsorted_list);
	pivot = choice_pivot(nums, len);
	push_chunk(a, b, unsorted_list, 0);
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
