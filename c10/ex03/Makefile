CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= ft_hexdump
SRC		= ft_hexdump.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
