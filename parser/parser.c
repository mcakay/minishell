/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:04:04 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/18 15:43:15 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_prompt(t_prompt *prompt, char **envp, char **strs)
{
	t_mini *cmds;

	cmds = NULL;
	prompt->pid = getpid();
	copy_envp(envp, prompt);
	get_cmds(&cmds, strs);
	prompt->cmds = cmds;
}

void	parser(char **strs, char **envp)
{
	t_prompt	prompt;

	for (int i = 0; strs[i]; i++)
		printf("strs[%d]:%s\n", i, strs[i]);
	init_prompt(&prompt, envp, strs);
}
