# ---------------------------------------------------------------------------- #
#	Define the compiler and flags											  												 #
# ---------------------------------------------------------------------------- #

CC			:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
MJ			 = -MJ $(patsubst $(BUILD_DIR)/$(OBJ_DIR)/%.o, $(BUILD_DIR)/$(JSON_DIR)/%.part.json, $@) 

# ---------------------------------------------------------------------------- #
#	Define the directories																										   #
# ---------------------------------------------------------------------------- #

BUILD_DIR	:= build
OBJ_DIR		:= obj
JSON_DIR	:= json

# ---------------------------------------------------------------------------- #
#	Define the source files													  													 #
# ---------------------------------------------------------------------------- #

SRCS	:= Account.cpp tests.cpp
OBJS	:= $(patsubst %.cpp, $(BUILD_DIR)/$(OBJ_DIR)/%.o, $(SRCS))

# ---------------------------------------------------------------------------- #
#	Define the target																													   #
# ---------------------------------------------------------------------------- #

NAME	:= account
JSON	:= compile_commands.json

# ---------------------------------------------------------------------------- #
#	Define the rules														 														 	   #
# ---------------------------------------------------------------------------- #

all:
		@$(MAKE) $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $@
		@./$(NAME) > out.log
		@printf "\n$(MAGENTA)[$(NAME)] Linking Success and create 'out.log'\n$(DEF_COLOR)"

$(BUILD_DIR)/$(OBJ_DIR)/%.o : %.cpp | dir_guard
		@$(CC) $(CFLAGS) -c $< -o $@ $(MJ)

clean:
		@$(RM) -r $(BUILD_DIR)
		@printf "$(BLUE)[$(NAME)] obj. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean:
		@$(RM) -r $(BUILD_DIR) $(NAME) $(JSON) out.log
		@printf "$(BLUE)[$(NAME)] obj. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"
		@printf "$(CYAN)[$(NAME)] exec. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

re:
		@$(MAKE) fclean
		@$(MAKE) all
		@printf "$(GREEN)[$(NAME)] Cleaned and rebuilt everything!\n$(DEF_COLOR)"

json:
		@$(MAKE) --always-make --keep-going all
		@(echo '[' && find . -name "*.part.json" | xargs cat && echo ']') > $(JSON)

dir_guard:
		@mkdir -p $(BUILD_DIR)/$(OBJ_DIR) $(BUILD_DIR)/$(JSON_DIR)

.PHONY: all clean fclean re dir_guard

# ---------------------------------------------------------------------------- #
#	Define the colors																													   #
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
