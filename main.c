/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/31 06:04:23 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char		**lexed;
	t_prompt	*parsed;
	char		**env;

	(void)argc;
	(void)argv;
	env = copy_env(envp);
	g_global.envp = env;
	g_global.status = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		char *line = readline("\033[1;32mminishell\033[0m$ ");
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