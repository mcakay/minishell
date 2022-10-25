/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:11 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/25 20:25:15 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	my_pwd(void)
{
	char	*path;

	path = getwd(NULL);
	printf("%s\n", path);
	free (path);
}

void	my_echo(t_command *a)
{
	int	i;

	i = 2;
	if (a->full_cmd[1] && a->full_cmd[1][0] == '-' && a->full_cmd[1][1] == 'n')
	{
		while (a->full_cmd[i] && a->full_cmd[i][0] == '-'
			&& a->full_cmd[i][1] == 'n')
			i++;
		if (a->full_cmd[i])
		{
			printf("%s", a->full_cmd[i]);
			i++;
			while (a->full_cmd[i])
				printf(" %s", a->full_cmd[i++]);
		}
	}
	else if (a->full_cmd[1])
	{
		printf("%s", a->full_cmd[1]);
		while (a->full_cmd[i])
			printf(" %s", a->full_cmd[i++]);
		printf("\n");
	}
	else
		printf("\n");
}

void	my_env(t_prompt *p)
{
	int	i;

	i = 0;
	while (p->envp[i] && check_equal(p->envp[i]))
		printf("%s\n", p->envp[i++]);
}

int	my_cd(t_prompt *p, t_command *a)
{
	char	*pwd;

	if (!a->full_cmd[1])
		chdir(getenv("HOME"));
	else
	{
		if (chdir(a->full_cmd[1]) == -1)
		{
			perror(ft_strjoin("cd: ", a->full_cmd[1]));
			return (0);
		}
	}
	if (is_present(p->envp, "OLDPWD"))
		del_env(p, "OLDPWD");
	add_env(p, ft_strjoin(ft_strdup("OLDPWD="), getenv("OLDPWD")));
	if (is_present(p->envp, "PWD"))
		del_env(p, "PWD");
	pwd = getwd(NULL);
	add_env(p, ft_strjoin(ft_strdup("PWD="), pwd));
	free (pwd);
	return (0);
}
