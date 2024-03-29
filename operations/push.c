/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:19:33 by fmai              #+#    #+#             */
/*   Updated: 2021/12/26 16:11:51 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*handle_from(t_stack *stack)
{
	int		cnt_list;
	t_node	*top;

	cnt_list = cnt_dllist(stack);
	if (cnt_list == 0)
		return (NULL);
	top = stack->top;
	if (cnt_list == 1)
	{
		stack->bottom = NULL;
		stack->top = NULL;
	}
	else
	{
		connect_nodes(stack->bottom, stack->top->next);
		stack->top = stack->bottom->next;
	}
	return (top);
}

void	handle_to(t_stack *stack, t_node *node)
{
	int	cnt_list;

	if (node == NULL)
		return ;
	cnt_list = cnt_dllist(stack);
	stack->top = node;
	if (cnt_list == 0)
	{
		stack->bottom = node;
		connect_nodes(node, node);
		return ;
	}
	connect_nodes(node, stack->bottom->next);
	connect_nodes(stack->bottom, node);
	stack->top = node;
}

void	push(t_stack *to, t_stack *from)
{
	t_node	*node;

	node = handle_from(from);
	handle_to(to, node);
}

// take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty.
void	push_a(t_stack *a, t_stack *b)
{
	if (b == NULL)
		return ;
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

// take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_stack *a, t_stack *b)
{
	if (a == NULL)
		return ;
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
