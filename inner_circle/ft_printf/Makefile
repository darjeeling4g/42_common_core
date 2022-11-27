
SRCS	= ft_printf.c \
		  ft_printf_parser.c \
		  ft_printf_printer.c \

OBJS	= $(SRCS:.c=.o)

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

%.o:		%.c
			$(CC) $(CFLAG) -c $^ -o $@

all:		$(NAME)

$(NAME): $(OBJS)
		make bonus -C libft
		mv libft/libft.a .
		ar rc $(NAME) $(OBJS)

bonus:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus

