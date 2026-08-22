NAME = rush01
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c utils.c visibility.c solver.c grid.c
OBJS = $(SRCS:.c=.o)
HEADER = rush01.h

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
