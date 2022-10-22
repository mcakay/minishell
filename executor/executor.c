/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:28:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/22 15:51:10 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	exec(t_command *cmd, t_prompt parsed)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd->prev == NULL)
			dup2(cmd->fd[1], 1);
		else
		{
			dup2(cmd->prev->fd[0], cmd->fd[0]);
			if (cmd->next != NULL)
				dup2(cmd->fd[1], 1);
			else
				dup2(cmd->fd[1], cmd->next->fd[0]);
		}
		close(cmd->fd[0]);
		close(cmd->fd[1]);
		execve(cmd->full_path, cmd->full_cmd, parsed.envp);
	}
	else
		waitpid(pid, NULL, 0);
}

void	executor(t_prompt parsed)
{
	t_command	*curr;
	pid_t		pid;

	add_path_to_cmds(&parsed);
	init_pipes(&parsed);
	curr = parsed.cmds->next;
	if (curr == NULL)
	{
		pid = fork();
		if (pid == 0)
			execve(parsed.cmds->full_path, parsed.cmds->full_cmd, parsed.envp);
		else
			waitpid(pid, NULL, 0);
	}
	while (curr)
	{
		pid = fork();
		if (pid == 0)
			exec(curr->prev, parsed);
		else
		{
			close(curr->prev->fd[0]);
			close(curr->prev->fd[1]);
			waitpid(pid, NULL, 0);
		}
		curr = curr->next;
	}
}