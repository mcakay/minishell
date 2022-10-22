/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:28:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/22 04:16:55 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	exec(t_command *first, t_command *second, t_prompt parsed)
{
	int fd[2];
	pid_t pid1;
	pid_t pid2;

	pid1 = fork();
	pipe(fd);
	if (pid1 == 0)
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			execve(first->full_path, first->full_cmd, parsed.envp);
		}
		else
		{
			dup2(fd[0], 0);
			close(fd[0]);
			close(fd[1]);
			execve(second->full_path, second->full_cmd, parsed.envp);
		}
		waitpid(pid2, NULL, 0);
	}
	waitpid(pid1, NULL, 0);
	return ;
}

void	executor(t_prompt parsed)
{
	add_path_to_cmds(&parsed);
	t_command *curr;
	curr = parsed.cmds;
	while (curr)
	{
		if (curr->next)
		{
			exec(curr, curr->next, parsed);
			curr = curr->next->next;
		}
		else
		{
			execve(curr->full_path, curr->full_cmd, parsed.envp);
			curr = curr->next;
		}
	}
}