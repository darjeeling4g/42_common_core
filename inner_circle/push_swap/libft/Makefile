
SRCS	= ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c

SRCS_GNL	= get_next_line.c \
			  get_next_line_utils.c

SRCS_PRINTF	= ft_printf.c \
			  ft_printf_parser.c \
			  ft_printf_printer.c \
			  ft_printf_printer_tools.c \
			  ft_printf_printer_utils.c \
			  ft_printf_sub_printer.c

OBJS	= $(SRCS:.c=.o)

OBJS_GNL	= $(SRCS_GNL:.c=.o)

OBJS_PRINTF	= $(SRCS_PRINTF:.c=.o)

SRCS_BONUS	= ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstlast.c \
			  ft_lstmap.c \
			  ft_lstnew.c \
			  ft_lstsize.c

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAG) -c $^ -o $@

$(NAME): $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
		ar rc $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)

bonus : $(OBJS) $(OBJS_BONUS) $(OBJS_GNL) $(OBJS_PRINTF)
		ar rc $(NAME) $(OBJS) $(OBJS_BONUS) $(OBJS_GNL) $(OBJS_PRINTF)
		touch bonus

clean:
			$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_GNL) $(OBJS_PRINTF) bonus

fclean:		clean
			$(RM) $(NAME)

re:
		make fclean
		make all

.PHONY:		all clean fclean re
