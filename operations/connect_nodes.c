/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:17:42 by fmai              #+#    #+#             */
/*   Updated: 2021/12/26 11:18:18 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// node_1のnextをnode_2にし、node_2のprevをnode_1にする
void	connect_nodes(t_node *node_1, t_node *node_2)
{
	node_1->next = node_2;
	node_2->prev = node_1;
}
