/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:40:00 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 06:48:36 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	is_null_cmd(t_command *curr, t_prompt *prompt)
{
	if (curr->full_path == NULL
		&& is_builtin1(curr->full_cmd[0]) == 0
		&& is_builtin2(curr->full_cmd[0]) == 0)
	{
		if (prompt->path == NULL)
		{
			printf("minishell: %s: No such file or directory\n",
				curr->full_cmd[0]);
			g_global.status = 1;
		}
		else
		{
			if (is_redirection_exec(curr) == 0)
			{
				printf("minishell: %s: command not found\n", curr->full_cmd[0]);
				g_global.status = 127;
			}
			else
				curr->is_only_redir = 1;
		}
	}
}

void	add_path_to_cmds(t_prompt *prompt)
{
	t_command	*curr;

	curr = prompt->cmds;
	while (curr)
	{
		curr->is_only_redir = 0;
		get_redirections(curr);
		curr->full_path = access_check(prompt->path, curr->full_cmd[0]);
		if (is_redirection_exec(curr) == 0
			&& curr->full_cmd[0][0] == '\0' && g_global.quotes--)
		{
			free(curr->full_path);
			curr->full_path = NULL;
		}
		is_null_cmd(curr, prompt);
		curr = curr->next;
	}
}

char	*add_path(char *path, char *cmd)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp, cmd);
	free(tmp);
	return (tmp2);
}

char	*access_check(char **path, char *cmd)
{
	int		i;
	char	*full_command;

	i = 0;
	if (path == NULL)
		return (NULL);
	while (path[i] && cmd)
	{
		if (is_builtin1(cmd) || is_builtin2(cmd))
			return (ft_strdup(cmd));
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		full_command = add_path(path[i], cmd);
		if (access(full_command, X_OK) == 0)
			return (full_command);
		free(full_command);
		i++;
	}
	return (NULL);
}
