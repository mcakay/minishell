NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

READLINE = -L/usr/include -lreadline

LEXER = ./lexer/lexer.c ./lexer/lexer_quote_handler.c ./lexer/lexer_quote_counter.c\
./lexer/lexer_utils.c ./lexer/lexer_remove_quotes.c ./lexer/lexer_calc_size.c ./lexer/lexer_add_env.c

PARSER = ./parser/parser.c ./parser/parser_cmd.c ./parser/parser_path.c ./parser/parser_redirection.c \
./parser/parser_redirection_io.c

EXECUTOR = ./executor/executor.c ./executor/executor_access.c ./executor/executor_pipes.c

UTILS = free.c envp.c

LIBFT = ./libft/libft.a

SRCS = main.c $(LEXER) $(UTILS) $(PARSER) $(EXECUTOR) 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(READLINE) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)  

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./libft

$(READLINE):
	@make -C ./lib/readline

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft


re: fclean all

.PHONY: all clean fclean re