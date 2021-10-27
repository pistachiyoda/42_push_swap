NAME = push_swap
CC = gcc
CFILES = main.c init_stack.c\
		./operations/swap.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(CFILES:.c=.o)
LIBFT_PATH = ./42_libft_new/

all: $(NAME)
$(NAME): $(OBJ) libft
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