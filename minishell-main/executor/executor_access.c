/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:40:00 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 14:47:36 by hseven           ###   ########.fr       */
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
			return (printf("zortshell: %s: command not found\n",
					curr->full_cmd[0]));
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

char	*access_check(char **path, char *cmd)
{
	int		i;
	char	*full_command;

	i = 0;
	while (path[i])
	{
		full_command = add_path(path[i], cmd);
		if (access(full_command, X_OK) == 0)
			return (full_command);
		i++;
	}
	return (NULL);
}
