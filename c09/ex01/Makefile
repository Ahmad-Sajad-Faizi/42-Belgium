CC	= cc
CFLAGS	= -Wall -Wextra - Werror
SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	= $(SRCS:.c=.o)
INCS	= -I includes
NAME	= libft.a

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	rm -f $(OBJS)

fclen: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
