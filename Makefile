NAME        := push_swap
BONUS_NAME	:= checker

CC          := cc
CFLAGS      := -Wall -Werror -Wextra -g
LIBFT       := libft/libft.a

DIR_SRCS    := src
BN_DIR_SRCS	:= checker
DIR_OBJS    := .objs
BN_DIR_OBJS := .bonus_objs
DIR_INCS    := include

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

BONUS_SRCS		:= checker/checker.c \

OBJS		:= $(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))
BONUS_OBJS	:= $(addprefix $(BN_DIR_OBJS)/, $(BONUS_SRCS.c=.o))
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

$(BN_DIR_OBJS_OBJS)/%.o: $(BN_DIR_OBJS)/%.c $(BN_INCS) Makefile $(LIBFT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(BN_DIR_INCS) -c $< -o $@
	@echo "$(BLUE)Compiling: $<$(END)"


all		:	$(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $@
	@echo "$(GREEN)$@ created$(END)"

bonus : $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $@
	@echo "$(GREEN)BONUS DONE\n"

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(DIR_OBJS)
	@make clean -C libft
	@echo "$(CYAN)Cleaned$(END)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "$(CYAN)Full clean$(END)"

re: fclean all

.PHONY: all clean fclean bonus re
