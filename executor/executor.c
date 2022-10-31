/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:28:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/31 02:39:52 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void    close_all_pipes(t_prompt *prompt)
{
    t_command   *curr;
    curr = prompt->cmds;
    while (curr->next)
    {
        close(curr->fd[0]);
        close(curr->fd[1]);
        curr = curr->next;
    }
}
void route_pipes(t_command *cmd)
{
    if (cmd->prev == NULL)	
	{
		if (cmd->outfile)
			dup2(cmd->outfile, 1);
		else 
			dup2(cmd->fd[1], 1);
	}
    else if (cmd->next == NULL)
		dup2(cmd->prev->fd[0], 0);
    else
    {
        dup2(cmd->prev->fd[0], 0);
        dup2(cmd->fd[1], 1);
    }
}
void exec(t_command *cmd, t_prompt parsed)
{
    pid_t   pid;
    pid = fork();
    if (pid == 0)
    {
        route_pipes(cmd);
		close_all_pipes(&parsed);
        if (is_builtin(cmd->full_cmd[0]))
			exec_builtin(cmd);
        else
			execve(cmd->full_path, cmd->full_cmd, g_global.envp);
    }
    else
        cmd->pid = pid;
}

void wait_cmd(t_prompt *prompt)
{
    int status;
    t_command *cmd;
    cmd = prompt->cmds;
    close_all_pipes(prompt);
    while (cmd)
    {
        waitpid(cmd->pid, &status, 0);
        cmd = cmd->next;
    }
}
void    executor(t_prompt parsed)
{
    t_command   *curr;
    if (add_path_to_cmds(&parsed))
        return ;
	g_global.status = 0;
    init_pipes(&parsed);
	if (get_redirections(&parsed.cmds))
		return ;
	curr = parsed.cmds;
    while (curr)
    {
        exec(curr, parsed);
        curr = curr->next;
    }
    wait_cmd(&parsed);
    close_all_pipes(&parsed);
}