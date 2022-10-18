/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:10:43 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/18 13:08:36 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	**strs;

	while (42)
	{
		char *line = readline("minishell$ ");
		add_history(line);
		strs = ft_split(line, ' ');
		parser(strs, envp);
	}
	return (0);
}