/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:14:09 by mai               #+#    #+#             */
/*   Updated: 2021/12/27 22:31:24 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include	<stddef.h>
# include	<stdio.h> // 後で消す
# include	<stdbool.h>
# include	<stdlib.h>
# include	"./42_libft_new/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
}	t_stack;

void	create_nodes(int num, char **num_list, t_stack *stack);
t_node	*create_node(int value);
void	connect_nodes(t_node *node_1, t_node *node_2);
void	push_chunk(t_stack *stack, int value);
int		pop_chunk(t_stack *stack);

// operations/swap.c
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_s(t_stack *a, t_stack *b);

// operations/push.c
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

// operations/rotate.c
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);

// operations/recers_rotate.c
void	rev_rotate_a(t_stack *a);
void	rev_rotate_b(t_stack *b);
void	rev_rotate_r(t_stack *a, t_stack *b);

// operations/cnt_dllist.c
int		cnt_dllist(t_stack *stack);

// sort/quicksort.c
void	quicksort(t_stack *a, t_stack *b);

// sort/sort_small_values.c
void	sort_two_values(t_stack *stack, void (*swap)(t_stack *));
void	sort_three_values(
	t_stack *stack, void (*swap)(t_stack *),
	void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *)
);
void	rotate_multi(t_stack *stack, int num, void (*rotate)(t_stack *));
void	sort_less_than_six_values_a(t_stack *a, t_stack *b, int len);
void	sort_and_push_less_than_six_values_b(t_stack *a, t_stack *b, int len);

// sort/sort_utils1.c
bool	is_sorted(t_stack *stack);
int	get_min_index(t_stack *stack);
int	choice_pivot(int *nums, int cnt);
int *sort_nums(t_stack *stack);

// sort/sort_utils2.c
void	split_a_stack(t_stack *a, t_stack *b, int len, t_stack *unsorted_list);
void	split_b_stack(t_stack *a, t_stack *b, t_stack *unsorted_list);
bool	is_splittable(t_stack *stack);
void	add_min_values(t_stack *a, t_stack *b, int b_len);

// sort/sort_utils3.c
void	move_unsorted_chunk(t_stack *a, t_stack *b, t_stack *unsorted_list);

// sort/sort_utils4.c
int	get_min_value(t_stack *stack);
#endif
