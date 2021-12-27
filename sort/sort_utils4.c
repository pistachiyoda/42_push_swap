/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:29:32 by fmai              #+#    #+#             */
/*   Updated: 2021/12/27 22:31:18 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// stack中の最小値を返す
int	get_min_value(t_stack *stack)
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
