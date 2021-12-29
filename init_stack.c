/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:16:38 by fmai              #+#    #+#             */
/*   Updated: 2021/12/29 22:33:37 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_stack *stack, int value)
{
	t_node	*chunk;

	chunk = create_node(value);
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

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	append_node(t_node *first_node, t_node *new_node)
{
	t_node	*current_node;

	current_node = first_node;
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = new_node;
	new_node->prev = current_node;
}

void	create_nodes(int num, char **num_list, t_stack *stack)
{
	int		value;
	int		cnt;
	t_node	*node;

	cnt = 0;
	num_list++;
	while (num > cnt)
	{
		value = ft_atoi(*num_list);
		node = create_node(value);
		if (cnt == 0)
			stack->top = node;
		else
			append_node(stack->top, node);
		num_list++;
		cnt++;
	}
	stack->bottom = node;
	node = stack->top;
	node->prev = stack->bottom;
	node = stack->bottom;
	node->next = stack->top;
}
