/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_invalid_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:23:08 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 23:07:24 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
	sign = 1;
	if (arg[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	else if (arg[0] == '+')
		i = 1;
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

bool	has_duplicate(t_stack *stack)
{
	int		cnt;
	int		i;
	int		j;
	t_node	*node_1;
	t_node	*node_2;

	cnt = cnt_dllist(stack);
	node_1 = stack->top;
	node_2 = stack->top;
	i = cnt;
	while (i)
	{
		j = cnt;
		while (j)
		{
			if (i != j && node_1->value == node_2->value)
				return (true);
			node_2 = node_2->next;
			j--;
		}
		node_1 = node_1->next;
		i--;
	}
	return (false);
}

void	free_memories_and_print_error(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 0);
	free_memories_and_exit(a, b, NULL, 1);
}
