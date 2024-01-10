NAME = push_swap
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = main.c list_creation.c split.c free_list.c stack_modify.c stack_utils.c rotate_command.c reverse_rotate_command.c testiprintti.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT)/libft.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT) -lft
	make clean

$(LIBFT)/libft.a:
	make -C $(LIBFT)
	make bonus -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re