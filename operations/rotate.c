/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:15:05 by fmai              #+#    #+#             */
/*   Updated: 2021/12/26 16:15:07 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *x)
{
	t_node	*old_top;
	t_node	*old_second;
	t_node	*old_bottom;

	if (x->top == NULL)
		return ;
	old_top = x->top;
	old_second = x->top->next;
	old_bottom = x->bottom;
	x->bottom = old_top;
	x->top = old_second;
	x->bottom->prev = old_bottom;
}

// shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

// shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

// ra and rb at the same time.
void	rotate_r(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
