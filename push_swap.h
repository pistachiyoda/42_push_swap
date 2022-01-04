/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:20:22 by fmai              #+#    #+#             */
/*   Updated: 2022/01/04 17:39:40 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include	<stddef.h>
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

// sort/sort.c
void	sort(t_stack *a, t_stack *b);
void	quicksort(t_stack *a, t_stack *b, int a_len);

// sort/split_stack.c
void	split_a_stack(
			t_stack *a, t_stack *b, int len, t_stack *unsorted_nums_list);
void	split_b_stack(t_stack *a, t_stack *b, t_stack *unsorted_list);

// sort/sort_utils.c
int		get_min_index(t_stack *stack);
bool	is_splittable(t_stack *stack);
void	add_min_values(t_stack *a, t_stack *b, int b_len);
void	handle_b_min(t_stack *b, int *min);
int		get_min_value(t_stack *stack);

// sort/sort_small_values.c
void	sort_two_values(t_stack *stack, void (*swap)(t_stack *));
void	sort_three_values(
			t_stack *stack, void (*swap)(t_stack *),
			void (*rotate)(t_stack *), void (*rev_rotate)(t_stack *)
			);
void	rotate_multi(t_stack *stack, int num, void (*rotate)(t_stack *));
void	sort_less_than_six_values_a(t_stack *a, t_stack *b, int len);
void	sort_and_push_less_than_six_values_b(t_stack *a, t_stack *b, int len);

// sort/sort_nums.c
int		*sort_nums(t_stack *stack);

// sort/handle_chunk.c
void	push_chunk(t_stack *a, t_stack *b, t_stack *stack, int value);
int		pop_chunk(t_stack *stack);
void	move_unsorted_chunk(t_stack *a, t_stack *b, t_stack *unsorted_list);

// sort/connect_nodes.c
void	connect_nodes(t_node *node_1, t_node *node_2);

// init_stack.c
t_stack	*create_stack(void);
void	create_nodes(
			int num, char **num_list, t_stack *stack_a, t_stack *stack_b);
t_node	*create_node(int value);

// utils.c
int		cnt_dllist(t_stack *stack);
bool	is_sorted(t_stack *stack);

// free_memories_and_exit.c
void	free_memories_and_exit(t_stack *a, t_stack *b, t_stack *unsorted_list);

// handle_invalid_input.c
bool	is_valid_num(int argc, char **argv);
bool	has_duplicate(t_stack *stack);
int		print_error(void);
#endif
