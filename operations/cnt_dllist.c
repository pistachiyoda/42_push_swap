/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnt_dllist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:15:12 by fmai              #+#    #+#             */
/*   Updated: 2021/12/26 11:17:08 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// スタック（双方向連結リスト）のノード数を計算して返す
int	cnt_dllist(t_stack *stack)
{
	int		cnt;
	t_node	*node;

	node = stack->top;
	if (node == NULL)
		return (0);
	cnt = 1;
	while (node->next != stack->top)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}
