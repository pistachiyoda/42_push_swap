/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:15:12 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 15:39:20 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Calculates the number of nodes in the stack then return
int	cnt_dllist(t_stack *stack)
{
	int		cnt;
	t_node	*node;

	node = stack->top;
	if (node == NULL)
		return (0);
	cnt = 1;
	while (node->next != stack->top)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}

// Returns true if the stack contents are sorted, false if they are not.
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
