
SRCS	= pipex.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

NAME	= pipex

LIBFT	= libft.a
LIBFT_DIR	= libft

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAG) -c $^ -o $@

$(NAME):	$(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -lft -L $(LIBFT_DIR) $(OBJS) -o $@

$(LIBFT) :
		make bonus -C libft

clean:
			make clean -C libft
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(LIBFT_DIR)/$(LIBFT)

re:			
		make fclean
		make all

.PHONY:		all clean fclean re
