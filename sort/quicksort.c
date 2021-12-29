/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:38:22 by fmai              #+#    #+#             */
/*   Updated: 2021/12/29 14:10:10 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_a_small_vals(t_stack *a, t_stack *b, int a_len)
{
	if (a_len == 3)
		return (sort_three_values(a, swap_a, rotate_a, rev_rotate_a));
	if (a_len <= 6)
		return (sort_less_than_six_values_a(a, b, a_len));
}

void	handle_b_small_vals(t_stack *a, t_stack *b, int b_len)
{
	if (b_len == 1)
		push_a(a, b);
	if (b_len == 2)
		sort_two_values(b, swap_b);
	if (b_len == 3)
		sort_three_values(b, swap_b, rotate_b, rev_rotate_b);
}

int	handle_b_3_to_6(t_stack *a, t_stack *b, int b_len, t_stack *unsorted_list)
{
	sort_and_push_less_than_six_values_b(a, b, b_len);
	if (cnt_dllist(b) == 0 && is_sorted(a))
		return (0);
	move_unsorted_chunk(a, b, unsorted_list);
	return (1);
}

void	quicksort(t_stack *a, t_stack *b, int a_len)
{
	int		b_len;
	t_stack	*unsorted_list;

	unsorted_list = (t_stack *)malloc(sizeof(t_stack));
	split_a_stack(a, b, a_len, unsorted_list);
	while (cnt_dllist(unsorted_list) >= 0)
	{
		while (is_splittable(b))
			split_b_stack(a, b, unsorted_list);
		b_len = cnt_dllist(b);
		handle_b_small_vals(a, b, b_len);
		if (b_len > 3 && b_len <= 6)
		{
			if (handle_b_3_to_6(a, b, b_len, unsorted_list) == 1)
				continue ;
			return ;
		}
		add_min_values(a, b, b_len);
		if (cnt_dllist(b) == 0 && is_sorted(a))
			return ;
		move_unsorted_chunk(a, b, unsorted_list);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int		a_len;

	a_len = cnt_dllist(a);
	if (a_len <= 6)
		return (handle_a_small_vals(a, b, a_len));
	return (quicksort(a, b, a_len));
}
