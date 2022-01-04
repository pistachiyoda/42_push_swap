/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:35:03 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 23:19:07 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (!(is_valid_num(argc, argv)))
		free_memories_and_print_error(NULL, NULL);
	stack_a = create_stack();
	stack_b = create_stack();
	if (stack_a == NULL || stack_b == NULL)
		free_memories_and_exit(stack_a, stack_b, NULL, 1);
	create_nodes(argc - 1, argv, stack_a, stack_b);
	if (has_duplicate(stack_a))
		free_memories_and_print_error(stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort(stack_a, stack_b);
	free_memories_and_exit(stack_a, stack_b, NULL, 0);
}
