
SRCS	= ft_printf.c \
		  ft_printf_parser.c \
		  ft_printf_printer.c \
		  ft_printf_sub_printer.c \
		  ft_printer_tools.c \
		  ft_printer_utils.c


OBJS	= $(SRCS:.c=.o)

SRCS_BONUS = ft_printf_bonus.c \
			 ft_printf_parser_bonus.c \
			 ft_printf_printer_bonus.c \
			 ft_printf_sub_printer_bonus.c \
			 ft_printer_tools_bonus.c \
			 ft_printer_utils_bonus.c

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

LIBFT	= libft.a

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAG) -c $^ -o $@

$(NAME):	$(OBJS) $(LIBFT)
		cp $(LIBFT) $(NAME)
		ar rc $(NAME) $(OBJS)

bonus:	$(OBJS_BONUS) $(LIBFT)
		cp $(LIBFT) $(NAME)
		ar rc $(NAME) $(OBJS_BONUS)
		touch bonus

$(LIBFT) :
		make bonus -C libft
		cp libft/$(LIBFT) $(LIBFT)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			
		make fclean
		make all

.PHONY:		all clean fclean re

