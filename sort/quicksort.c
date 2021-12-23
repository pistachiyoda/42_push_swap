/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:58:57 by mai               #+#    #+#             */
/*   Updated: 2021/12/23 22:14:22 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quicksort(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;
	t_stack	*unsorted_list;

	if (is_sorted(a))
		return ;
	a_len = cnt_dllist(a);
	if (a_len == 3)
		return (sort_three_values(a, swap_a, rotate_a, rev_rotate_a));
	if (a_len <= 6)
		return (sort_less_than_six_values_a(a, b, a_len));
	unsorted_list = (t_stack *)malloc(sizeof(t_stack));
	split_a_stack(a, b, a_len, unsorted_list);
	while (cnt_dllist(unsorted_list) >= 0)
	{
		while (is_splittable(b))
			split_b_stack(a, b, unsorted_list);
		b_len = cnt_dllist(b);
		if (b_len == 1)
			push_a(a, b);
		if (b_len == 2)
			sort_two_values(b, swap_b);
		if (b_len == 3)
			sort_three_values(b, swap_b, rotate_b, rev_rotate_b);
		if (b_len > 3 && b_len <= 6)
		{
			sort_and_push_less_than_six_values_b(a, b, b_len);
			if (cnt_dllist(b) == 0 && is_sorted(a))
				return;
			move_unsorted_chunk(a, b, unsorted_list);
			continue;
		}

		add_min_values(a, b, b_len);
		if (cnt_dllist(b) == 0 && is_sorted(a))
			return;
		move_unsorted_chunk(a, b, unsorted_list);
	}
}
