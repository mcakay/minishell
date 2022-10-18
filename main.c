/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:10:43 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/17 12:27:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	while (42)
	{
		char *line = readline("minishell$ ");
		add_history(line);
		lexer(line, envp);
	}
	return (0);
}