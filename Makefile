NAME = push_swap
CC = gcc
CFILES = main.c init_stack.c free_memories_and_exit.c handle_invalid_input.c\
		./operations/swap.c ./operations/push.c ./operations/rotate.c ./operations/reverse_rotate.c ./operations/cnt_dllist.c\
		./sort/quicksort.c ./sort/sort_small_values.c ./sort/sort_utils1.c ./sort/sort_utils2.c ./sort/sort_utils3.c\
		./sort/sort_utils4.c ./operations/connect_nodes.c ./handle_chunk.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(CFILES:.c=.o)
LIBFT_PATH = ./42_libft_new/

all: $(NAME)
$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ./libft.a -o $(NAME)
libft:
	git submodule update -i
	make -C $(LIBFT_PATH)
	cp ./42_libft_new/libft.a .
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	rm -f libft.a
re: fclean all
