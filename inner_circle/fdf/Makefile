
SRCS	= fdf.c \
		  fdf_drawing.c \
		  fdf_drawing_utils.c \
		  fdf_handling.c \
		  fdf_init.c \
		  fdf_parsing.c \
		  fdf_rotation.c


OBJS	= $(SRCS:.c=.o)

SRCS_BONUS = fdf_bonus.c \
			 fdf_drawing_bonus.c \
			 fdf_drawing_utils_bonus.c \
			 fdf_handling_bonus.c \
			 fdf_init_bonus.c \
			 fdf_parsing_bonus.c \
			 fdf_rotation_bonus.c

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -O3

NAME	= fdf

LIBFT	= libft.a
LIBFT_DIR	= libft

MLX		= libmlx.dylib
MLX_DIR	= mlx

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAG) -c $^ -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) -lmlx -L . -lft -L $(LIBFT_DIR) $(OBJS) -o $@

bonus:	$(OBJS_BONUS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) -lmlx -L . -lft -L $(LIBFT_DIR) $(OBJS_BONUS) -o $@
		touch bonus

$(LIBFT) :
		make bonus -C libft

$(MLX) :
		make -C mlx
		cp $(MLX_DIR)/$(MLX) $(MLX)

clean:
			make clean -C libft
			make clean -C mlx
			$(RM) $(OBJS) $(OBJS_BONUS) bonus

fclean:		clean
			$(RM) $(NAME) $(MLX) $(LIBFT_DIR)/$(LIBFT)

re:			
		make fclean
		make all

.PHONY:		all clean fclean re
