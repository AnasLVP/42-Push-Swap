NAME	= push_swap
LIBFT	= libft/libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

OBJDIR	= obj
SRCS	= operations/swap.c operations/rotate.c operations/rrotate.c operations/push.c operations/count_operation.c \
			operations/extremum.c operations/count_operations_2.c parse_utils.c main.c sort_three.c \
			lists/ft_lstswap.c lists/create_list.c lists/ft_lstsorted.c lists/ft_lstnormalize.c \
			lists/lst_extremum.c lists/insert_index.c push_swap.c

OBJS	= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

ORANGE	= \033[0;33m
RESET	= \033[0m
PURPLE	= \033[1;35m


# Règle principale
all: $(NAME)
	@echo "$(PURPLE)✔ PUSH_SWAP Compiled$(RESET)"

# Compilation finale
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@ -g3

# Compilation des objets dans obj/
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -g3

# Compilation de la libft
$(LIBFT):
	@$(MAKE) --no-print-directory -C libft

# Nettoyage
clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) --no-print-directory -C libft clean
	@echo "$(ORANGE)🧹 PUSH_SWAP Cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C libft fclean
	@echo "$(ORANGE)🗑️  PUSH_SWAP Executable Cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re

