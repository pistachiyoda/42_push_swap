/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:17:42 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 15:43:50 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Make node_2 the next of node_1, and make node_1 the prev of node_2.
void	connect_nodes(t_node *node_1, t_node *node_2)
{
	node_1->next = node_2;
	node_2->prev = node_1;
}
