/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:36:56 by fmai              #+#    #+#             */
/*   Updated: 2021/12/27 23:36:59 by fmai             ###   ########.fr       */
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
	t_node	*one;
	t_node	*two;
	t_node	*three;

	one = stack->top;
	two = stack->top->next;
	three = stack->bottom;
	if (one->value < two->value && two->value < three->value)
		return ;
	if (one->value > two->value && two->value < three->value
		&& three->value > one->value)
		return (swap(stack));
	if (one->value > two->value && two->value < three->value
		&& three->value < one->value)
		return (rotate(stack));
	if (one->value < two->value && two->value > three->value
		&& three->value > one->value)
	{
		swap(stack);
		return (rotate(stack));
	}
	if (one->value > two->value && two->value > three->value
		&& three->value < one->value)
		swap(stack);
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
		if (min_index > (len - i) / 2)
			rotate_multi(a, (len - i) - min_index, rev_rotate_a);
		else
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
