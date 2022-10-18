NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

READLINE = -L/usr/include -lreadline

LIBFT = ./libft/libft.a

PARSER = ./parser/parser.c ./parser/parser_env.c ./parser/parser_cmd.c

SRCS = main.c $(PARSER)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(READLINE) -o $(NAME) $(LIBFT) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./libft

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft


re: fclean all

.PHONY: all clean fclean re