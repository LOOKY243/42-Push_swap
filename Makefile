CC = clang
NAME = push_swap
SRCS = ft_split.c \
		ft_strjoin.c \
		get_args.c \
		get_args2.c \
		main.c \
		permutations.c \
		permutations2.c \
		push_a_to_b.c \
		push_b_to_a.c \
		ft_printf/ft_char_funct.c \
		ft_printf/ft_int_funct.c \
		ft_printf/ft_printf.c
HEADER = push_swap.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wextra -Wall -g

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re