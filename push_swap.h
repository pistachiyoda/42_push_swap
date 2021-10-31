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

typedef struct s_stuck
{
    t_node  *top;
    t_node  *bottom;
}   t_stuck;

void    create_nodes(int num, char **num_list, t_stuck *stuck);
t_node	*create_node(int value);

// operations/swap.c
void    swap_a(t_stuck *a);
void    swap_b(t_stuck *b);
void    swap_s(t_stuck *a, t_stuck *b);

// operations/push.c
void    push_a(t_stuck *a, t_stuck *b);
void    push_b(t_stuck *a, t_stuck *b);

// operations/rotate.c
void rotate_a(t_stuck *a);
void rotate_b(t_stuck *b);
void rotate_r(t_stuck *a, t_stuck *b);

// operations/recers_rotate.c
void rev_rotate_a(t_stuck *a);
void rev_rotate_b(t_stuck *b);
void rev_rotate_r(t_stuck *a, t_stuck *b);

// operations/cnt_dllist.c
int     cnt_dllist(t_stuck *stuck);
#endif