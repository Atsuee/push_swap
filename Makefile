NAME        := push_swap
BONUS_NAME	:= checker

CC          := cc
CFLAGS      := -Wall -Werror -Wextra -g
LIBFT       := libft/libft.a

DIR_SRCS    := src
BN_DIR_SRCS := bonus
DIR_OBJS    := .objs
BN_DIR_OBJS := .bonus_objs
DIR_INCS    := include
BN_DIR_INCS := bonus

SRCS        := main.c \
					move_stack/push.c \
					move_stack/swap.c \
					move_stack/rotate.c \
					verif/verif.c \
					sort/help.c \
					move_stack/init.c \
					sort/sort.c \
					sort/sort_utils.c \
					sort/stack.c \
					move_stack/init_utils.c \
					move_stack/split_arg.c \
					move_stack/both.c \

BONUS_SRCS		:= 	main.c \
					checker.c \
					checker_utils.c \
					init.c \
					init_utils.c \
					instruction.c \
					instructions_utils.c \
					verif.c \

OBJS		:= $(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))
BONUS_OBJS	:= $(addprefix $(BN_DIR_OBJS)/, $(BONUS_SRCS:.c=.o))
INCS		:= $(addprefix $(DIR_INCS)/, push_swap.h)
BN_INCS		:= $(addprefix $(BN_DIR_INCS)/, checker.h)

BLUE        := \033[34m
YELLOW      := \033[33m
GREEN       := \033[32m
CYAN    	:= \033[36m
END         := \033[0m

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS) Makefile $(LIBFT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(DIR_INCS) -c $< -o $@
	@echo "$(BLUE)Compiling: $<$(END)"

$(BN_DIR_OBJS)/%.o: $(BN_DIR_SRCS)/%.c $(BN_INCS) Makefile $(LIBFT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(BN_DIR_INCS) -c $< -o $@
	@echo "$(BLUE)Compiling: $<$(END)"

all		:	$(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "$(GREEN)$@ created$(END)"

bonus : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(GREEN)BONUS DONE\n"

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(DIR_OBJS)
	@rm -rf $(BN_DIR_OBJS)
	@make clean -C libft
	@echo "$(CYAN)Cleaned$(END)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(BONUS_NAME)
	@make fclean -C libft
	@echo "$(CYAN)Full clean$(END)"

re: fclean all

.PHONY: all clean fclean bonus re
