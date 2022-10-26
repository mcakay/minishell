/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/27 00:46:39 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
}

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
	while (1)
	{
		char *line = readline("zortshell$ ");
		if (*line == '\0')
			continue ;
		add_history(line);
		lexed = lexer(line, env);
		(void)parsed;
		/*
		parsed = parser(lexed, envp);
		if (parsed == NULL)
			continue ;
		executor(*parsed);
		*/
		free_strs(lexed);
		free(line);
		//system("leaks minishell");
	}
	return (0);
}