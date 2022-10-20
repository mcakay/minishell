/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:11 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/20 20:24:47 by bkayan           ###   ########.fr       */
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

	if (!a->full_cmd[1])
	{
		home = getenv("HOME");
		while (*home != '=')
			home++;
		home++;
		chdir(home);
	}
	else
	{
		if (chdir(a->full_cmd[1]) == -1)
		{
			printf("minishell: cd: %s:", a->full_cmd[1]);
			printf(" No such file or directory");
		}
	}
	return (0);
}

/*
int	main()
{
	s_mini		*a;
	s_prompt	*p;

	p = ft_calloc(1, sizeof(s_prompt));
	p->

	p->
	a->
	return (0);
}
*/