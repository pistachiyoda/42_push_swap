/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:00:11 by mai               #+#    #+#             */
/*   Updated: 2021/12/16 13:12:33 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_notnum(int argc, char **argv)
{
	int i;
	int j;
	int cnt;

	i = 1;
	cnt = argc - 1;
	while (cnt > 0)
	{
		j = 0;
		if (argv[i][j] == '-')
			j = 1;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (true);
			j++;
		}
		cnt--;
		i++;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_node	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc == 1)
		return (0);
	if (is_notnum(argc, argv))
	{
		ft_putstr_fd("Error\n", 0);
		return (0);
	}
	return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	create_nodes(argc - 1, argv, stack_a);
	quicksort(stack_a, stack_b);
	return (0);
}
