NAME        = minishell
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g3 -O0 -fsanitize=address,undefined
INCLUDES    = -I includes

SRCS        = srcs/main.c srcs/signals.c srcs/shell.c srcs/main_aux.c srcs/main_aux_input.c srcs/tokenizer.c srcs/tokenizer_aux.c srcs/debuger_temp.c srcs/handle_quotes.c srcs/parser.c srcs/parser_check.c srcs/free_every.c srcs/parser_aux.c srcs/parser_aux_2.c srcs/parser_extension.c srcs/parser_heredoc.c srcs/parser_heredoc_aux.c srcs/heredoc.c srcs/heredoc_aux.c srcs/executor_aux.c srcs/executor.c srcs/executor_2.c srcs/general_aux.c srcs/expander.c srcs/expander_ultra.c srcs/expander_ultra_aux.c srcs/expander_finalizer.c srcs/path_resolver.c built/echo.c srcs/redirections.c 
OBJS        = $(SRCS:.c=.o)

HEADERS     = includes/minishell.h includes/shell.h includes/tokenizer.h includes/parser.h includes/status.h includes/signals.h includes/main_aux.h

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror"

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

