/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnt_dllist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:59:23 by mai               #+#    #+#             */
/*   Updated: 2021/11/19 22:07:31 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
