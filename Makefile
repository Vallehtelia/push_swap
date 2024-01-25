NAME = push_swap
LIBFT = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC	= main.c list_creation.c split.c error_check.c stack_modify.c \
	  stack_utils.c stack_utils_two.c rotate_command.c \
	  reverse_rotate_command.c sorting.c sort_three.c init_a_to_b.c \
	  init_b_to_a.c swap.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT)/libft.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT) -lft

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