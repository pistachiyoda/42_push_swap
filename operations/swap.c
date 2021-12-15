/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:59:59 by mai               #+#    #+#             */
/*   Updated: 2021/12/15 11:33:34 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_top(t_stack *stack)
{
	t_node	*top_to_second;
	t_node	*second_to_top;
	t_node	*third;
	t_node	*bottom;
	int		stack_size;

	stack_size = cnt_dllist(stack);
	if (stack_size <= 1)
		return ;
	if (stack_size == 2)
	{
		top_to_second = stack->top;
		stack->top = stack->bottom;
		stack->bottom = top_to_second;
		return ;
	}
	top_to_second = stack->top;
	second_to_top = top_to_second->next;
	third = second_to_top->next;
	second_to_top->prev = stack->bottom;
	second_to_top->next = top_to_second;
	top_to_second->prev = second_to_top;
	top_to_second->next = third;
	third->prev = top_to_second;
	bottom = stack->bottom;
	bottom->next = second_to_top;
	stack->top = second_to_top;
}

// swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
void	swap_a(t_stack *a)
{
	swap_top(a);
	ft_putstr_fd("sa\n", 1);
}

// swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
void	swap_b(t_stack *b)
{
	swap_top(b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_s(t_stack *a, t_stack *b)
{
	swap_top(a);
	swap_top(b);
	ft_putstr_fd("ss\n", 1);
}
