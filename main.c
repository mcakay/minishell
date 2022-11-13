/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/13 16:13:01 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_global(char **envp)
{
	g_global.envp = copy_env(envp);
	g_global.status = 0;
	g_global.pid = 1;
	g_global.here_doc = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

void	free_everything(char **lexed, t_prompt *parsed, char *line)
{
	free_strs(lexed);
	free_parsed(parsed);
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	char		**lexed;
	char		*line;
	t_prompt	*parsed;

	(void)argc;
	(void)argv;
	init_global(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			eof_handler(0);
		if (*line == '\0')
			continue ;
		add_history(line);
		lexed = lexer(line);
		if (!lexed)
			continue ;
		parsed = parser(lexed);
		if (parsed == NULL)
			continue ;
		executor(*parsed);
		free_everything(lexed, parsed, line);
	}
	return (0);
}
