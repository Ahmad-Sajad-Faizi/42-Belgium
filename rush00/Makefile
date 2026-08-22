NAME = rush
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_putchar.c rush.c main.c
OBJS = $(SRCS:.c=.o)
HEADER = rush.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
