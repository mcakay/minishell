NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

BUILTIN = ./builtin/builtin.c ./builtin/environment.c ./builtin/environment2.c

SRCS = $(BUILTIN)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS) -g -fsanitize=address

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