/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:00:11 by mai               #+#    #+#             */
/*   Updated: 2021/12/15 22:23:13 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	
	create_nodes(argc - 1, argv, stack_a);
	quicksort(stack_a, stack_b);
	
		// printf("a\n");
		// print_stack(stack_a);
		// printf("b\n");
		// print_stack(stack_b);
	return (0);
}
