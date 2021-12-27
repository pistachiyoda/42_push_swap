/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:57:48 by fmai              #+#    #+#             */
/*   Updated: 2021/12/27 22:37:58 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_unsorted_chunk_len2(t_stack *a, t_stack *b)
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

	if (a->top->value == min)
	{
		rotate_a(a);
		node = a->top;
		min = a->top->value;
		j = 1;
		while (chunk_len - i > j)
		{
			if (min > node->value)
				min = node->value;
			node = node->next;
			j++;
		}
		handle_b_min(b, &min);
	}
	else
		push_b(a, b);
}

// ソートされていない一番上にあるチャンクをstack_bに移動
// void	move_unsorted_chunk(t_stack *a, t_stack *b, t_stack *unsorted_list)
// {
// 	int		chunk_len;
// 	int		min;
// 	t_node	*node;
// 	int		i;

// 	chunk_len = pop_chunk(unsorted_list);
// 	if (chunk_len == 2)
// 		handle_unsorted_chunk_len2(a, b);
// 	min = a->top->value;
// 	node = a->top->next;
// 	i = 1;
// 	while (chunk_len > i)
// 	{
// 		if (min > node->value)
// 			min = node->value;
// 		node = node->next;
// 		i++;
// 	}
// 	i = 0;
// 	while (chunk_len > i)
// 	{
// 		handle_unsorted_chunk_node(a, b, min, chunk_len);
// 		i++;
// 	}
// }
void	move_unsorted_chunk(t_stack *a, t_stack *b, t_stack *unsorted_list)
{
	int	chunk_len;
	int min;
	t_node *node;
	int i;
	int j;
	int b_min;

	chunk_len = pop_chunk(unsorted_list);
	// printf("chunk_len = %d\n", chunk_len);
	if (chunk_len == 2)
	{
		sort_two_values(a, swap_a);
		rotate_a(a);
		rotate_a(a);
		return ;
	}
	// chunk内の最小値を見つける
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
	i = 0;
	while (chunk_len > i)
	{
		// そのchunkの最小値はスタックaの末尾に移動する
		if (a->top->value == min)
		{
			rotate_a(a);
			// スタックaのいま処理してるchunkとスタックbにpushした値の中のminを求めたい
			// chunk中で探す
			node = a->top;
			min = a->top->value;
			// printf("first_min = %d\n", min);
			j = 1;
			while (chunk_len - i > j)
			{
				if (min > node->value)
					min = node->value;
				node = node->next;
				j++;
			}
			// printf("min_after_check_chunk =%d\n", min);
			// bスタックから探す
			if (b->top)
			{
				b_min = get_min_value(b);
				if (b_min < min)
					min = b_min;
			}
			// printf("b_min = %d\n", b_min);
			// printf("new_min = %d\n", min);
		}
		else
		{

			push_b(a, b);
		}
		i++;
	}
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
