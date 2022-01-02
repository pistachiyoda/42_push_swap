/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:35:03 by fmai              #+#    #+#             */
/*   Updated: 2022/01/02 20:23:01 by fmai             ###   ########.fr       */
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
		return (print_error());
	stack_a = create_stack();
	stack_b = create_stack();
	if (stack_a == NULL || stack_b == NULL)
		free_memories_and_exit(stack_a, stack_b, NULL);
	create_nodes(argc - 1, argv, stack_a, stack_b);
	if (has_duplicate(stack_a))
		return (print_error());
	if (is_sorted(stack_a))
		return (0);
	sort(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
