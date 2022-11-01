/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/01 21:18:56 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char		**lexed;
	t_prompt	*parsed;
	char		**env;
	int status;

	(void)argc;
	(void)argv;
	env = copy_env(envp);
	g_global.envp = env;
	g_global.status = 0;
	g_global.check = 0;
	waitpid(-1, &status, 0);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler_in_process);
	while (1)
	{
		char *line = readline("\033[1;32mminishell\033[0m$ ");
		if (g_global.check == 1)
		{
			g_global.check = 0;
			free(line);
			continue ;
		}
		if (!line)
			ctrl_d();
		else if (*line == '\0')
			continue ;
		add_history(line);
		lexed = lexer(line, env);
		if (!lexed)
			continue ;
		parsed = parser(lexed, envp);
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