/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:11 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/20 19:44:30 by bkayan           ###   ########.fr       */
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
	char	*home;
	int		i;

	if (!a->full_cmd[1])
	{
		home = getenv("HOME");
		chdir(home);
	}
	else
	{
		if (chdir(a->full_cmd[1]) == -1)
		{
			printf("", %s);
		}
	}
	return (0);
}
