/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memories_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:42:34 by fmai              #+#    #+#             */
/*   Updated: 2022/01/01 23:45:26 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current_node;
	t_node	*prev_node;
	int		cnt;

	cnt = cnt_dllist(stack);
	if (cnt == 0)
		return (free(stack));
	current_node = stack->top;
	while (cnt)
	{
		if (cnt == 1)
		{
			free(current_node);
			break ;
		}
		prev_node = current_node;
		current_node = current_node->next;
		free(prev_node);
		cnt--;
	}
	free(stack);
}

void	free_memories_and_exit(t_stack *a, t_stack *b, t_stack *unsorted_list)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (unsorted_list)
		free_stack(unsorted_list);
	exit(1);
}
