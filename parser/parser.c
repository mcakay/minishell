/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/21 05:41:16 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_prompt(t_prompt *prompt, char **envp, char **strs)
{
	t_command *cmds;

	cmds = NULL;
	prompt->pid = getpid();
	copy_envp(envp, prompt);
	get_cmds(&cmds, strs);
	get_path(prompt);
	prompt->cmds = cmds;
}

t_prompt	parser(char **strs, char **envp)
{
	t_prompt	prompt;

	for (int i = 0; strs[i]; i++)
		printf("strs[%d]:%s\n", i, strs[i]);
	init_prompt(&prompt, envp, strs);
	return (prompt);
}