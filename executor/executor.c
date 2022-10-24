/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:28:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 05:56:58 by mcakay           ###   ########.fr       */
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
		if (cmd->next != NULL)
			dup2(cmd->next->fd[1], 1);
		if (cmd->prev != NULL)
			dup2(cmd->fd[0], 0);
		close(cmd->fd[0]);
		close(cmd->fd[1]);
		execve(cmd->full_path, cmd->full_cmd, parsed.envp);
	}
	else
	{
		close(cmd->fd[0]);
		close(cmd->fd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	executor(t_prompt parsed)
{
	t_command	*curr;

	if (add_path_to_cmds(&parsed))
		return ;
	init_pipes(&parsed);
	curr = parsed.cmds;
	while (curr)
	{
		exec(curr, parsed);
		curr = curr->next;
	}
	close_all_pipes(&parsed);
}