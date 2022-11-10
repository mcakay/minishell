/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:40:00 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/11 00:01:19 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	add_path_to_cmds(t_prompt *prompt)
{
	t_command	*curr;

	curr = prompt->cmds;
	while (curr)
	{
		curr->full_path = access_check(prompt->path, curr->full_cmd[0]);
		if (curr->full_path == NULL)
		{
			if (prompt->path == NULL)
				return (printf("minishell: %s: No such file or directory\n", curr->full_cmd[0]));
			if (curr->full_cmd[0] == NULL)
				return (1);
			else
				g_global.status = 127;
			return (printf("minishell: %s: command not found\n", curr->full_cmd[0]));
		}
		curr = curr->next;
	}
	return (0);
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

char 	*access_check(char **path, char *cmd)
{
	int	i;
	char	*full_command;

	i = 0;
	if (path == NULL)
		return (NULL);
	while (path[i] && cmd)
	{
		if (is_builtin1(cmd) || is_builtin2(cmd))
			return (cmd);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		full_command = add_path(path[i], cmd);
		if (access(full_command, X_OK) == 0)
			return (full_command);
		i++;
	}
	return (NULL);
}