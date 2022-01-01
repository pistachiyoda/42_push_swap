/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:26:59 by fmai              #+#    #+#             */
/*   Updated: 2022/01/02 00:07:26 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_stack *a, t_stack *b, t_stack *stack, int value)
{
	t_node	*chunk;

	chunk = create_node(value);
	if (chunk == NULL)
		free_memories_and_exit(a, b, stack);
	if (cnt_dllist(stack) == 0)
	{
		stack->top = chunk;
		stack->bottom = chunk;
		connect_nodes(chunk, chunk);
	}
	else
	{
		connect_nodes(stack->bottom, chunk);
		connect_nodes(chunk, stack->top);
		stack->top = chunk;
	}
}

int	pop_chunk(t_stack *stack)
{
	t_node	*chunk;
	int		chunk_val;
	int		len;

	len = cnt_dllist(stack);
	chunk = stack->top;
	if (len == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = stack->top->next;
		connect_nodes(stack->bottom, stack->top);
	}
	chunk_val = chunk->value;
	free(chunk);
	return (chunk_val);
}
