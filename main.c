/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/27 17:35:25 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d(void)
{
	printf("exit\n");
	exit(0);
}

//değiştir
void	sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int main(int argc, char **argv, char **envp)
{
	char		**lexed;
	t_prompt	*parsed;
	char		**env;

	(void)argc;
	(void)argv;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	env = copy_env(envp);
	g_global.envp = env;
	g_global.status = 0;
	while (1)
	{
		char *line = readline("zortshell$ ");
		if (!line)
			ctrl_d();
		else if(*line == '\0')
			continue ;
		add_history(line);
		lexed = lexer(line, env);
		parsed = parser(lexed, envp);
		if (parsed == NULL)
			continue ;
		executor(*parsed);
		free_strs(lexed);
		free(line);
		//system("leaks minishell");
	}
	return (0);
}
