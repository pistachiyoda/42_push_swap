/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:39:15 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 15:27:20 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// スタックの値から最小値の検索して返す
int		get_min_index(t_stack *stack)
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

// stack中の最小値を返す
int		get_min_value(t_stack *stack)
{
	t_node	*node;
	int		min;

	node = stack->top->next;
	min = stack->top->value;
	while (node != stack->top)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
	}
	return (min);
}
