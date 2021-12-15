/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:58:57 by mai               #+#    #+#             */
/*   Updated: 2021/12/15 22:23:10 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quicksort(t_stack *a, t_stack *b)
{
	int	a_len;
	int	c_a_len;
	int	b_len;
	int	sorted_len;

	if (is_sorted(a))
		return ;
	a_len = cnt_dllist(a);
	if (a_len == 3)
		return (sort_three_values(a, swap_a, rotate_a, rev_rotate_a));
	if (a_len <= 6)
		return (sort_less_than_six_values_a(a, b, a_len));
	sorted_len = 0;
	// printf("a_len:%d\n", a_len);
	split_a_stack(a, b, a_len);
	// printf("++a(before sort)++\n");
	// print_stack(a);
	// printf("++b(before sort)++\n");
	// print_stack(b);
	b_len = cnt_dllist(b);
	while (a_len != sorted_len)
	{
			// printf("test1\n");
		while (is_splittable(b))
		{
			// printf("test2\n");
			split_b_stack(a, b);
			// rotate_b(b);
		}
		b_len = cnt_dllist(b);
		c_a_len = cnt_dllist(a);
		// printf("b_len: %d\n", b_len);
		sorted_len += b_len;
		if (b_len == 1)
			push_a(a, b);
		if (b_len == 2)
			sort_two_values(b, swap_b);
	// printf("#####b(before sort)++\n");
	// print_stack(b);
		if (b_len == 3)
			sort_three_values(b, swap_b, rotate_b, rev_rotate_b);
	// printf("#####b(after sort)++\n");
	// print_stack(b);
		if (b_len > 3 && b_len <= 6)
		{
			sort_and_push_less_than_six_values_b(a, b, b_len);
			continue;
		}
		// printf("@@@@@@@blen:%d\n", b_len);
		// printf("++a(before add_mint)++\n");
		// print_stack(a);
		// printf("++b(before add_min)++\n");
		// print_stack(b);
		add_min_values(a, b, b_len);
		// printf("++a(after add_mint)++\n");
		// print_stack(a);
		// printf("++b(after add_min)++\n");
		// print_stack(b);
		push_without_sorted(a, b, a_len, sorted_len);
	}
}
