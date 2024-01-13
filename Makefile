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

all: fonc_printf $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) printf/*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fonc_printf:
	$(MAKE) -C printf

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C printf

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C printf

re: fclean all
