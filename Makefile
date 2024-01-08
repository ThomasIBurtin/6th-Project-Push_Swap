CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = algo.c \
      commande.c \
      fonc_rotation_algo.c \
      ft_atoi.c \
      push.c \
      sort_a_b.c \
      sort_final.c \
      tools_algo.c \
      ft_split.c \
      tools.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all