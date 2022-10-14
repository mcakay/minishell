NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

READLINE = -L/usr/include -lreadline

LIBFT = ./libft/libft.a

SRCS = main.c lexer.c quote_handler.c

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