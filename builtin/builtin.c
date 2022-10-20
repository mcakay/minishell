/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:11 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/20 17:54:32 by bkayan           ###   ########.fr       */
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
	if (!a->full_cmd[1])
		return (0);
	else if (a->full_cmd[1][0] == '.')
	{
		if (a->full_cmd[1][1] == '.')
		{
			// !
			chdir (getenv("PATH"));
		}
		return (0);
	}
	else
	{
		if ()
			a;
		else
			chdir();
	}
	return (0);
}

int	main(void)
{
	my_pwd();
	return (0);
}
