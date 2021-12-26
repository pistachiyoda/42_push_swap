/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:35:03 by fmai              #+#    #+#             */
/*   Updated: 2021/12/26 23:00:34 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_int_range(char str_num, int sign, long long val)
{
	if (sign == 1 && ((long long)10 * val + (str_num - '0')) > 2147483647)
		return (false);
	if (sign == -1 && ((long long)10 * val + (str_num - '0')) > 2147483648)
		return (false);
	return (true);
}

bool	is_int_num(char *arg)
{
	int			i;
	long long	val;
	int			sign;

	val = 0;
	i = 0;
	if (arg[0] == '-')
	{
		i = 1;
		sign = -1;
	}
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (false);
		if (!(is_int_range(arg[i], sign, val)))
			return (false);
		val = 10 * val + (arg[i] - '0');
		i++;
	}
	return (true);
}

bool	is_valid_num(int argc, char **argv)
{
	int			i;

	i = 1;
	while (argc-- - 1 > 0)
	{
		if (!is_int_num(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	has_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

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
				!ft_strncmp(argv[i], argv[j], ft_strlen(argv[i]))
				&& ft_strlen(argv[i]) == ft_strlen(argv[j])
			)
				return (true);
			j ++;
		}
		i ++;
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
	if (!(is_valid_num(argc, argv)))
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
