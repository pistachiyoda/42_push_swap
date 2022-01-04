/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:26:59 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 17:42:13 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

// Remove top node(chunk) of unsorted_list and return that value.
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

// Move the values in the chunk to stack b.
// If minimum value turned out, just rotate and put it to stack a's last.
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

void	handle_unsorted_chunk_len2(t_stack *a)
{
	sort_two_values(a, swap_a);
	rotate_a(a);
	rotate_a(a);
	return ;
}

// Move the top unsorted chunk to stack_b.
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
