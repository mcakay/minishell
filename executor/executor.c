/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:28:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/21 06:11:43 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	exec(t_prompt parsed, char *cmd)
{
	printf("asd\n");
	execve(cmd, parsed.cmds->full_cmd, parsed.envp);
}

void	executor(t_prompt parsed)
{
	char *cmd;

	cmd = access_check(parsed.path, parsed.cmds->full_cmd[0]);
	
	if (cmd)
		exec(parsed, cmd);
	else
		printf("minishell: %s: command not found\n", parsed.cmds->full_cmd[0]);
}