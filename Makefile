NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -lreadline

LEXER = ./lexer/lexer.c ./lexer/lexer_quote_handler.c ./lexer/lexer_quote_counter.c\
./lexer/lexer_utils.c ./lexer/lexer_utils2.c ./lexer/lexer_remove_quotes.c ./lexer/lexer_calc_size.c ./lexer/lexer_add_env.c\
./lexer/lexer_utils3.c

PARSER = ./parser/parser.c ./parser/parser_cmd.c ./parser/parser_path.c ./parser/parser_redirection.c \
./parser/parser_redirection_io.c ./parser/parser_here_doc_append.c

EXECUTOR = ./executor/executor.c ./executor/executor_access.c ./executor/executor_pipes.c ./executor/executor_builtin.c\
./executor/executor_redirection.c ./executor/executor_utils.c

BUILTIN = ./builtin/builtin.c ./builtin/environment.c ./builtin/export.c ./builtin/builtin2.c

UTILS = free.c free_redirections.c envp.c signal.c

LIBFT = ./libft/libft.a

SRCS = main.c $(LEXER) $(UTILS) $(PARSER) $(EXECUTOR) $(BUILTIN)

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)  

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./libft

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@rm -f heredoc

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft


re: fclean all

.PHONY: all clean fclean re