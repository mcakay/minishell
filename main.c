/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 07:33:12 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_global(char **envp, char **argv, int argc)
{
	g_global.envp = copy_env(envp);
	g_global.status = 0;
	g_global.pid = 1;
	g_global.check = 0;
	g_global.heredoc = 0;
	g_global.quotes = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	(void)argc;
	(void)argv;
}

void	free_everything(char **lexed, t_prompt *parsed, char *line)
{
	free_strs(lexed);
	free_parsed(parsed);
	free(line);
}

int	loop(char **line, char ***lexed)
{
	*line = readline("minishell$ ");
	if (g_global.check == 1)
	{
		g_global.check = 0;
		free(*line);
		return (1);
	}
	if (!*line)
		eof_handler(0);
	if (**line == '\0')
		return (1);
	add_history(*line);
	*lexed = lexer(*line);
	if (!*lexed)
	{
		free(*line);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char		**lexed;
	char		*line;
	t_prompt	*parsed;

	line = NULL;
	lexed = NULL;
	init_global(envp, argv, argc);
	while (1)
	{
		if (loop(&line, &lexed))
			continue ;
		parsed = parser(lexed);
		if (parsed == NULL)
		{
			free_everything(lexed, parsed, line);
			continue ;
		}
		executor(*parsed);
		g_global.quotes = 0;
		free_everything(lexed, parsed, line);
	}
	return (0);
}
