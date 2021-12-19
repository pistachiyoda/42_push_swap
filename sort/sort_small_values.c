/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:15:36 by mai               #+#    #+#             */
/*   Updated: 2021/12/19 14:05:25 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two_values(t_stack *stack, void (*swap)(t_stack *))
{
	if (stack->top->value < stack->bottom->value)
		return ;
	swap(stack);
}

void	sort_three_values(
	t_stack *stack, void (*swap)(t_stack *),
	void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *)
)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->top;
	second = stack->top->next;
	third = stack->bottom;
	if (first->value < second->value && second->value < third->value)
		return;
	if (first->value > second->value
		&& second->value < third->value
		&& third->value > first->value)
		return (swap(stack));
	if (first->value > second->value
		&& second->value > third->value
		&& third->value < first->value)
	{
		swap(stack);
		return (rev_rotate(stack));
	}
	if (first->value > second->value
		&& second->value < third->value
		&& third->value < first->value)
		return (rotate(stack));
	if (first->value < second->value
		&& second->value > third->value
		&& third->value > first->value)
	{
		swap(stack);
		return (rotate(stack));
	}
	return (rev_rotate(stack));
}

void	rotate_multi(t_stack *stack, int num, void (*rotate)(t_stack *))
{
	while (num)
	{
		rotate(stack);
		num--;
	}
}

void	sort_less_than_six_values_a(t_stack *a, t_stack *b, int len)
{
	int		i;
	int		min_index;
	t_node	*node;

	i = 0;
	while (i < len - 3)
	{
		min_index = get_min_index(a);
		rotate_multi(a, min_index, rotate_a);
		push_b(a, b);
		i++;
	}
	if (!is_sorted(a))
		sort_three_values(a, swap_a, rotate_a, rev_rotate_a);
	i = 0;
	while (i < len - 3)
	{
		push_a(a, b);
		i++;
	}
}

void	sort_and_push_less_than_six_values_b(t_stack *a, t_stack *b, int len)
{
	int		i;
	int		min_index;
	t_node	*node;

	i = 0;
	while (i < len - 3)
	{
		min_index = get_min_index(b);
		if (min_index > (len - i) / 2)
			rotate_multi(b, (len - i) - min_index, rev_rotate_b);
		else
			rotate_multi(b, min_index, rotate_b);
		push_a(a, b);
		rotate_a(a);
		i++;
	}
	if (!is_sorted(b))
		sort_three_values(b, swap_b, rotate_b, rev_rotate_b);
	i = 0;
	while (i < 3)
	{
		push_a(a, b);
		rotate_a(a);
		i++;
	}
}
