/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:28:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/22 20:55:19 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	close_all_pipes(t_prompt *prompt)
{
	t_command	*curr;

	curr = prompt->cmds;
	while (curr->next)
	{
		close(curr->fd[0]);
		close(curr->fd[1]);
		curr = curr->next;
	}
}

void	exec(t_command *cmd, t_prompt parsed)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd->prev == NULL)
		{
			dup2(cmd->fd[1], 1);
			close_all_pipes(&parsed);
		}
		else
		{
			if (cmd->next != NULL)
			{
				dup2(cmd->prev->fd[0], 0);
				dup2(cmd->fd[1], 1);
				close_all_pipes(&parsed);
			}
			else
			{
				dup2(cmd->prev->fd[0], 0);
				close_all_pipes(&parsed);
			}
		}
		execve(cmd->full_path, cmd->full_cmd, parsed.envp);
	}
	if (cmd->next == NULL)
	{
		close_all_pipes(&parsed);
		waitpid(pid, NULL, 0);
	}
}

void	executor(t_prompt parsed)
{
	t_command	*curr;
	pid_t		pid;

	if (add_path_to_cmds(&parsed))
		return ;
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
		exec(curr->prev, parsed);
		exec(curr, parsed);
		curr = curr->next;
	}
}