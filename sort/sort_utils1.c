/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:39:15 by fmai              #+#    #+#             */
/*   Updated: 2021/12/27 21:57:53 by fmai             ###   ########.fr       */
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

// スタックの値から最小値の検索して返す
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

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

// cnt個の数字の配列numsを昇順に選択ソートして返す
int	*selection_sort(int cnt, int *nums)
{
	int	i;
	int	j;
	int	k;
	int	min;

	i = 0;
	while (i < cnt)
	{
		min = nums[i];
		k = i;
		j = i + 1;
		while (j < cnt)
		{
			if (nums[j] < min)
			{
				min = nums[j];
				k = j;
				swap(&nums[i], &nums[k]);
			}
			j++;
		}
		i++;
	}
	return (nums);
}

// スタックの値を昇順にソート済みの配列の形にして返す
int	*sort_nums(t_stack *stack)
{
	int		cnt;
	int		i;
	int		*nums;
	t_node	*node;

	cnt = cnt_dllist(stack);
	i = 0;
	nums = (int *)malloc(cnt);
	node = stack->top;
	while (i < cnt)
	{
		nums[i] = node->value;
		node = node->next;
		i++;
	}
	return (selection_sort(cnt, nums));
}
