/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:28:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 06:53:51 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "../minishell.h"

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

void	route_pipes(t_command *cmd)
{
	if (cmd->prev == NULL)
		dup2(cmd->fd[1], 1);
	else if (cmd->next == NULL)
		dup2(cmd->prev->fd[0], 0);
	else
	{
		dup2(cmd->prev->fd[0], 0);
		dup2(cmd->fd[1], 1);
	}
	if (cmd->outfile)
		dup2(cmd->outfile, 1);
	if (cmd->infile)
		dup2(cmd->infile, 0);
}

void	exec(t_command *cmd, t_prompt parsed)
{
	pid_t	pid;

	g_global.pid = 0;
	pid = fork();
	if (pid == 0)
	{
		route_pipes(cmd);
		close_all_pipes(&parsed);
		if (is_builtin1(cmd->full_cmd[0]))
			exec_builtin1(cmd);
		else
		{
			execve(cmd->full_path, cmd->full_cmd, g_global.envp);
			exit(0);
		}
	}
	else
		cmd->pid = pid;
}

void	wait_cmd(t_prompt *prompt)
{
	int			status;
	t_command	*cmd;

	cmd = prompt->cmds;
	close_all_pipes(prompt);
	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		cmd = cmd->next;
	}
	g_global.pid = 1;
}

void	executor(t_prompt parsed)
{
	t_command	*curr;

	g_global.status = 0;
	add_path_to_cmds(&parsed);
	if (g_global.status != 0)
		return ;
	init_pipes(&parsed);
	curr = parsed.cmds;
	while (curr)
	{
		if (curr->here_doc_list)
			if (here_doc(curr))
				return ;
		append_mode(curr);
		if (curr->is_only_redir == 0)
		{
			if (is_builtin2(curr->full_cmd[0]))
				exec_builtin2(curr);
			else
				exec(curr, parsed);
		}
		curr = curr->next;
	}
	close_all(&parsed);
}
