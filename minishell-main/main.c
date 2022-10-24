/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:32:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 15:37:43 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		**lexed;
	t_prompt	*parsed;
	char		*line;

	(void)argc;
	(void)argv;
	while (1)
	{
		line = readline("zortshell$ ");
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
