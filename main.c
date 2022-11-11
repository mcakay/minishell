/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 01:15:10 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_global(char **envp)
{
	g_global.envp = copy_env(envp);
	g_global.status = 0;
	g_global.pid = 1;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

int main(int argc, char **argv, char **envp)
{
	char		**lexed;
	t_prompt	*parsed;

	(void)argc;
	(void)argv;
	init_global(envp);
	while (1)
	{
		char *line = readline("minishell$ ");
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
		free_strs(lexed);
		free(line);
		//free_parsed(parsed);
		free(parsed);
		//system("leaks minishell");
	}
	return (0);
}
