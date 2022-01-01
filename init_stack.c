/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:16:38 by fmai              #+#    #+#             */
/*   Updated: 2022/01/01 21:41:01 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
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
