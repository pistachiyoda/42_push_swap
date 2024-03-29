/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:17:33 by fmai              #+#    #+#             */
/*   Updated: 2021/12/26 16:17:36 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_stack *x)
{
	t_node	*old_top;
	t_node	*old_bottom_prev;
	t_node	*old_bottom;

	if (x->top == NULL)
		return ;
	old_top = x->top;
	old_bottom_prev = x->bottom->prev;
	old_bottom = x->bottom;
	x->top = old_bottom;
	x->top->next = old_top;
	x->bottom = old_bottom->prev;
}

// shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rev_rotate_a(t_stack *a)
{
	rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

// shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rev_rotate_b(t_stack *b)
{
	rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

// rra and rrb at the same time.
void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
