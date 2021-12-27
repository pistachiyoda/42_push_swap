/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:57:48 by fmai              #+#    #+#             */
/*   Updated: 2021/12/27 23:05:15 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_unsorted_chunk_len2(t_stack *a)
{
	sort_two_values(a, swap_a);
	rotate_a(a);
	rotate_a(a);
	return ;
}

void	handle_b_min(t_stack *b, int *min)
{
	int		b_min;

	if (b->top)
	{
		b_min = get_min_value(b);
		if (b_min < *min)
			*min = b_min;
	}
}

void	handle_unsorted_chunk_node(
	t_stack *a, t_stack *b, int min, int chunk_len)
{
	t_node	*node;
	int		i;
	int		j;

	i = 0;
	while (chunk_len > i)
	{
		if (a->top->value == min)
		{
			rotate_a(a);
			node = a->top;
			min = a->top->value;
			j = 1;
			while (chunk_len - i > j ++)
			{
				if (min > node->value)
					min = node->value;
				node = node->next;
			}
			handle_b_min(b, &min);
		}
		else
			push_b(a, b);
		i ++;
	}
}

// ソートされていない一番上にあるチャンクをstack_bに移動
void	move_unsorted_chunk(t_stack *a, t_stack *b, t_stack *unsorted_list)
{
	int		chunk_len;
	int		min;
	t_node	*node;
	int		i;

	chunk_len = pop_chunk(unsorted_list);
	if (chunk_len == 2)
		return (handle_unsorted_chunk_len2(a));
	min = a->top->value;
	node = a->top->next;
	i = 1;
	while (chunk_len > i)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
		i++;
	}
	handle_unsorted_chunk_node(a, b, min, chunk_len);
}

// スタックからピボットとする中央値を選択する
int	choice_pivot(int *nums, int cnt)
{
	int	mid;

	if ((cnt % 2) == 0)
		mid = cnt / 2 - 1;
	else
		mid = (cnt + 1) / 2 - 1;
	return (nums[mid]);
}
