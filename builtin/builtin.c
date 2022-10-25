/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:11 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/25 13:33:28 by bkayan           ###   ########.fr       */
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

void	my_echo(t_mini *a)
{
	int	i;

	i = 2;
	if (a->full_cmd[1][0] == '-' && a->full_cmd[1][1] == 'n')
	{
		while (a->full_cmd[i][0] == '-' && a->full_cmd[i][1] == 'n')
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

int	my_cd(t_prompt *p, t_mini *a)
{
	char	*path;

	if (!a->full_cmd[1])
	{
		path = getenv("HOME");
		while (*path != '=')
			path++;
		path++;
		chdir(path);
	}
	else
	{
		if (chdir(a->full_cmd[1]) == -1)
		{
			perror(a->full_cmd[1]);
			return (0);
		}
	}
	if (is_present(p->envp, "OLDPWD"))
		del_env(p, "OLDPWD");
	add_env(p, getenv("OLDPWD"));
	if (is_present(p->envp, "PWD"))
		del_env(p, "PWD");
	add_env(p, getenv("PWD"));
	return (0);
}

int	main()
{
	t_mini		*a;
	t_prompt	*p;

	p = ft_calloc(1, sizeof(t_prompt));
	p->envp = ft_calloc(3, sizeof(char *));
	p->envp[0] = ft_strjoin(ft_strdup("PWD="), getenv("PWD"));
	p->envp[1] = ft_strjoin(ft_strdup("HOME="), getenv("HOME"));
	a = ft_calloc(1, sizeof(t_mini));
	a->full_cmd = ft_calloc(3, sizeof(char *));
	a->full_cmd[0] = ft_calloc(5, sizeof(char));
	a->full_cmd[0] = ft_strdup("export");
	a->full_cmd[1] = ft_strdup("a =1");

	my_env(p);
	my_export(p, a);
	printf("şimdi:\n");
	my_env(p);

	return (0);
}
//pwd tamam
//my_env tamam
//echo segmen
//unset tamam
//export segmen
//cd bus