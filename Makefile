CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = commande.c \
      ft_check_args.c \
      ft_split.c \
      ft_atoi.c \
      push.c \
      radix_sort.c \
      simple_sort.c \
      tools.c \
      attribution_index.c \
      utils.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC)  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all