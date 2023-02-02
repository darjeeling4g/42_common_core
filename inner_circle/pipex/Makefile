
SRCS	= pipex.c

OBJS	= $(SRCS:.c=.o)

SRCS_BONUS	= pipex_bonus.c

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

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
		cp $(LIBFT_DIR)/$(LIBFT) $(LIBFT)
		$(CC) $(CFLAGS) -lft -L $(LIBFT_DIR) $(OBJS) -o $@

bonus: $(OBJS_BONUS) $(LIBFT)
		cp $(LIBFT_DIR)/$(LIBFT) $(LIBFT)
		$(CC) $(CFLAGS) -lft -L $(LIBFT_DIR) $(OBJS_BONUS) -o $@
		touch bonus

$(LIBFT):
		make bonus -C libft

clean:
			make clean -C libft
			$(RM) $(OBJS) $(OBJS_BONUS) bonus

fclean:		clean
			$(RM) $(NAME) $(LIBFT) $(LIBFT_DIR)/$(LIBFT)

re:			
		make fclean
		make all

.PHONY:		all clean fclean re
