# ---------------------------------------------------------------------------- #
#	Define the compiler and flags											   #
# ---------------------------------------------------------------------------- #

CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror
CPPFLAGS			= -I includes -I $(LIBFT_DIR)/includes
LDFLAGS				= -L $(LIBFT_DIR)
LDLIBS				:= -l ft

# ---------------------------------------------------------------------------- #
#	Define the libraries													   #
# ---------------------------------------------------------------------------- #

LIBFT_DIR			:= libft

# ---------------------------------------------------------------------------- #
#	Define the directories													   #
# ---------------------------------------------------------------------------- #

SRC_DIR				:= sources

MD_DIR				:= mandatory
PARSER_DIR			:= parser
DEQUE_DIR			:= deque
BONUS_DIR			:= bonus

BUILD_DIR			:= build
OBJ_DIR				:= obj

# ---------------------------------------------------------------------------- #
#	Define the source files													   #
# ---------------------------------------------------------------------------- #

SRCS				:= $(addprefix $(SRC_DIR)/$(MD_DIR)/, push_swap.c push_swap_utils.c)
SRCS				+= $(addprefix $(SRC_DIR)/$(MD_DIR)/, push_swap_greedy.c push_swap_greedy_utils.c)
SRCS				+= $(addprefix $(SRC_DIR)/$(PARSER_DIR)/, push_swap_parser.c)
SRCS				+= $(addprefix $(SRC_DIR)/$(DEQUE_DIR)/, push_swap_deque.c push_swap_deque_utils.c)
SRCS_BONUS			:= $(addprefix $(SRC_DIR)/$(BONUS_DIR)/, push_swap_bonus.c push_swap_utils_bonus.c)
SRCS_BONUS			+= $(addprefix $(SRC_DIR)/$(PARSER_DIR)/, push_swap_parser.c)
SRCS_BONUS			+= $(addprefix $(SRC_DIR)/$(DEQUE_DIR)/, push_swap_deque.c push_swap_deque_utils.c)

define SRCS_GOAL
	$(if $(filter bonus, $(MAKECMDGOALS)), $(SRCS_BONUS), $(SRCS))
endef

OBJS				:= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/$(OBJ_DIR)/%.o, $(SRCS_GOAL))

# ---------------------------------------------------------------------------- #
#	Define the variables for progress bar									   #
# ---------------------------------------------------------------------------- #

TOTAL_FILES			:= $(shell echo $(SRCS_GOAL) | wc -w)
COMPILED_FILES		:= 0
STEP				:= 100

# ---------------------------------------------------------------------------- #
#	Define the target														   #
# ---------------------------------------------------------------------------- #

LIBFT				:= $(LIBFT_DIR)/libft.a
NAME				:= push_swap
BONUS				:= checker

# ---------------------------------------------------------------------------- #
#	Define the rules														   #
# ---------------------------------------------------------------------------- #

all:
		@$(MAKE) -j $(NAME)

$(LIBFT):
		@$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
		@$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $^ -o $@
		@printf "\n$(MAGENTA)[$(NAME)] Linking Success\n$(DEF_COLOR)"

$(BUILD_DIR)/$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | dir_guard
		@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
		@$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
		@$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
		@printf "$(SAVECUR) $(DELINE) $(YELLOW)[$(NAME)] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR) $(RESTCUR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

bonus: $(LIBFT) $(OBJS)
		@$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $^ -o $(BONUS)
		@touch bonus
		@printf "\n$(MAGENTA)[$(NAME)] Linking Success\n$(DEF_COLOR)"

clean:
		@$(MAKE) -C $(LIBFT_DIR) clean
		@$(RM) -r $(BUILD_DIR) bonus
		@printf "$(BLUE)[$(NAME)] obj. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean:
		@$(MAKE) -C $(LIBFT_DIR) fclean
		@$(RM) -r $(BUILD_DIR) $(NAME) $(BONUS) bonus
		@printf "$(BLUE)[$(NAME)] obj. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"
		@printf "$(CYAN)[$(NAME)] exec. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

re:
		@$(MAKE) fclean
		@$(MAKE) all
		@printf "$(GREEN)[$(NAME)] Cleaned and rebuilt everything!\n$(DEF_COLOR)"

dir_guard:
		@mkdir -p $(addprefix $(BUILD_DIR)/$(OBJ_DIR)/, $(MD_DIR) $(PARSER_DIR) $(DEQUE_DIR) $(BONUS_DIR))

norm:
		@(norminette | grep Error) || (printf "$(GREEN)[$(NAME)] Norminette Success\n$(DEF_COLOR)")

.PHONY: all clean fclean re dir_guard norm

# ---------------------------------------------------------------------------- #
#	Define the colors														   #
# ---------------------------------------------------------------------------- #

DELINE = \033[K
CURSUP = \033[A
SAVECUR = \033[s
RESTCUR = \033[u

DEF_COLOR	= \033[1;39m
GRAY		= \033[1;90m
RED			= \033[1;91m
GREEN		= \033[1;92m
YELLOW		= \033[1;93m
BLUE		= \033[1;94m
MAGENTA		= \033[1;95m
CYAN		= \033[1;96m
WHITE		= \033[1;97m
