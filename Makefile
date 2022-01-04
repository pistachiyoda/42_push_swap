NAME = push_swap
CC = gcc
CFILES = main.c init_stack.c free_memories_and_exit.c handle_invalid_input.c utils.c\
		./operations/swap.c ./operations/push.c ./operations/rotate.c ./operations/reverse_rotate.c\
		./sort/sort.c ./sort/sort_small_values.c ./sort/split_stack.c ./sort/sort_nums.c ./sort/sort_utils.c ./sort/handle_chunk.c ./sort/connect_nodes.c
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
