/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:00:11 by mai               #+#    #+#             */
/*   Updated: 2021/12/16 23:10:14 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_not_intnum(int argc, char **argv)
{
	int i;
	int j;
	int cnt;
	long long val;
	int	sign;

	i = 1;
	cnt = argc - 1;
	while (cnt > 0)
	{
		val = 0;
		j = 0;
		sign = 1;
		if (argv[i][j] == '-')
		{
			j = 1;
			sign = -1;
		}
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (true);
			if (sign == 1 && ((long long)10 * val + (argv[i][j] - '0')) > 2147483647)
				return (true);
			if (sign == -1 && ((long long)10 * val + (argv[i][j] - '0')) > 2147483648)
				return (true);
			val = 10 * val + (argv[i][j] - '0');
			j++;
		}
		cnt--;
		i++;
	}
	return (false);
}

bool has_duplicate(int argc, char **argv)
{
	int	i;
	int j;
	
	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i == j)
			{
				j ++;
				continue ;
			}
			if (
				!ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) &&
				ft_strlen(argv[i]) == ft_strlen(argv[j])
			) {
				return (true);
			}
			j ++;
		}
		i ++;
	}
	return false;
}

int	main(int argc, char **argv)
{
	t_node	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc == 1)
		return (0);
	if (is_not_intnum(argc, argv))
	{
		ft_putstr_fd("Error\n", 0);
		return (0);
	}
	if (has_duplicate(argc, argv))
	{
		ft_putstr_fd("Error\n", 0);
		return (0);
	}
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	create_nodes(argc - 1, argv, stack_a);
	quicksort(stack_a, stack_b);
	return (0);
}
