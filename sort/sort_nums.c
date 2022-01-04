/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:58:50 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 17:41:31 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	*selection_sort(int cnt, int *nums)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < cnt)
	{
		min = nums[i];
		j = i + 1;
		while (j < cnt)
		{
			if (nums[j] < min)
			{
				min = nums[j];
				swap(&nums[i], &nums[j]);
			}
			j++;
		}
		i++;
	}
	return (nums);
}

// crash対応
// Return the stack values in the form of a sorted array in ascending order.
int	*sort_nums(t_stack *stack)
{
	int		cnt;
	int		i;
	int		*nums;
	t_node	*node;

	cnt = cnt_dllist(stack);
	i = 0;
	nums = (int *)malloc(sizeof(int) * cnt);
	if (nums == NULL)
		exit(1);
	node = stack->top;
	while (i < cnt)
	{
		nums[i] = node->value;
		node = node->next;
		i++;
	}
	return (selection_sort(cnt, nums));
}
