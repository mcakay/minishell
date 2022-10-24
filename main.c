/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 03:34:19 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char 	**lexed;
	t_prompt *parsed;

	(void)argc;
	(void)argv;
	while (1)
	{
		char *line = readline("zortshell$ ");
		if (*line == '\0')
			continue ;
		add_history(line);
		lexed = lexer(line, envp);
		parsed = parser(lexed, envp);
		if (parsed == NULL)
			continue ;
		executor(*parsed);
	}
	return (0);
}