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

t_node *create_nodes(int num, char **num_list);
t_node	*create_node(int value);
#endif