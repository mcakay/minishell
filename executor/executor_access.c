/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:40:00 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/21 06:02:24 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

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
	while (path[i])
	{
		full_command = add_path(path[i], cmd);
		if (access(full_command, X_OK) == 0)
			return (full_command);
		i++;
	}
	return (NULL);
}