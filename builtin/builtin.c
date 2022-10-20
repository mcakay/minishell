/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:11 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/20 18:23:31 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

void	my_pwd(void)
{
	char	*path;

	path = getwd(NULL);
	printf("%s\n", path);
	free (path);
}

void	my_echo(t_mini *a)
{
	int	i;

	if (a->full_cmd[1][0] == '-' && a->full_cmd[1][1] == 'n')
	{
		if (a->full_cmd[2])
		{
			printf("%d", a->full_cmd[2]);
			i = 3;
			while (a->full_cmd[i])
				printf(" %d", a->full_cmd[i++]);
		}
	}
	else if (a->full_cmd[1])
	{
		printf("%d", a->full_cmd[1]);
		i = 2;
		while (a->full_cmd[i])
			printf(" %d", a->full_cmd[i++]);
		printf("\n");
	}
	else
		printf("\n");
}

int	my_cd(t_prompt *p, t_mini *a)
{
	char	*path;
	int		i;

	if (!a->full_cmd[1])
		return (0);
	else if (a->full_cmd[1][0] == '.')
	{
		if (a->full_cmd[1][1] == '.')
		{
			path = getwd(NULL);
			i = ft_strlen(path) - 1;
			while (path[i])
			{
				if (i == '\\')
					path[i] == 0;
				i--;
			}
			chdir (path);
			free (path);
		}
		return (0);
	}
	else
	{
		path = getwd(NULL);
		if ()
			printf(" cd: %s: No such file or directory\n",  a->full_cmd[1]);
		else
		{
			path = ft_strjoin(path, a->full_cmd);
			chdir();
		}
		free (path);
	}
	return (0);
}
