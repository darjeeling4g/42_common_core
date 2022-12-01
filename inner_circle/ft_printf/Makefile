
SRCS	= ft_printf.c \
		  ft_printf_parser.c \
		  ft_printf_printer.c \
		  ft_printer_utils.c \

OBJS	= $(SRCS:.c=.o)

SRCS_BONUS = $(SRCS) \
			 ft_printf_bonus.c \
			 ft_printf_parser_bonus.c \
			 ft_printf_printer_bonus.c \
			 ft_printer_utils_bonus.c \

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAG) -c $^ -o $@

$(NAME): $(OBJS)
		make bonus -C libft
		cp libft/libft.a $(NAME)
		ar rc $(NAME) $(OBJS)

bonus:		$(OBJS_BONUS)
		make bonus -C libft
		cp libft/libft.a $(NAME)
		ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
		make -t bonus

clean:
			$(RM) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			
		make fclean
		make all

.PHONY:		all clean fclean re

