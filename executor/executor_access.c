/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:40:00 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 04:48:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	add_path_to_cmds(t_prompt *prompt)
{
	t_command	*curr;

	curr = prompt->cmds;
	while (curr)
	{
		get_redirections(curr);
		curr->full_path = access_check(prompt->path, curr->full_cmd[0]);
		if (curr->full_path == NULL && curr->full_cmd[0] != NULL)
		{
			if (prompt->path == NULL)
			{
				printf("minishell: %s: No such file or directory\n",
					curr->full_cmd[0]);
				g_global.status = 1;
			}
			else
			{
				printf("minishell: %s: command not found\n", curr->full_cmd[0]);
				g_global.status = 127;
			}
		}
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
