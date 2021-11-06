#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdio.h> // 後で消す
#include <stdbool.h>
#include <stdlib.h>
#include "./42_libft_new/libft.h"

typedef struct s_node
{
    int value;
    struct s_node* next;
    struct s_node* prev;    
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    t_node  *bottom;
}   t_stack;

void    create_nodes(int num, char **num_list, t_stack *stack);
t_node	*create_node(int value);

// operations/swap.c
void    swap_a(t_stack *a);
void    swap_b(t_stack *b);
void    swap_s(t_stack *a, t_stack *b);

// operations/push.c
void    push_a(t_stack *a, t_stack *b);
void    push_b(t_stack *a, t_stack *b);

// operations/rotate.c
void rotate_a(t_stack *a);
void rotate_b(t_stack *b);
void rotate_r(t_stack *a, t_stack *b);

// operations/recers_rotate.c
void rev_rotate_a(t_stack *a);
void rev_rotate_b(t_stack *b);
void rev_rotate_r(t_stack *a, t_stack *b);

// operations/cnt_dllist.c
int     cnt_dllist(t_stack *stack);
#endif