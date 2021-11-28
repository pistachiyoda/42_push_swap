/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:58:57 by mai               #+#    #+#             */
/*   Updated: 2021/11/28 14:18:44 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quicksort(t_stack *a, t_stack *b)
{
	int	len;
	int	b_len;
	int	sorted_len;

	if (is_sorted(a))
		return ;
	len = cnt_dllist(a);
	if (len == 3)
		return (sort_three_values(a, swap_a, rotate_a, rev_rotate_a));
	if (len <= 6)
		return (sort_less_than_six_values_a(a, b, len));
	sorted_len = 0;
	split_a_stack(a, b, len);
	b_len = cnt_dllist(b);
	while (len != sorted_len)
	{
		while (is_splittable(b))
		{
			split_b_stack(a, b);
			rotate_b(b);
		}
		b_len = cnt_dllist(b);
		if (b_len == 2)
			sort_two_values(b, swap_b);
		else if (b_len == 3)
			sort_three_values(b, swap_b, rotate_b, rev_rotate_b);
		if (b_len > 3 && b_len <= 6)
			sort_and_push_less_than_six_values_b(a, b, b_len);
		else
			add_min_values(a, b, b_len);
		sorted_len += b_len;
		push_without_sorted(a, b, len, sorted_len);
	}
}
