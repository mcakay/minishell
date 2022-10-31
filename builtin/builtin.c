/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:11 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/29 00:51:36 by mcakay           ###   ########.fr       */
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

int is_flag(t_command *a, int i)
{
    int j;
    j = 1;
    while (a->full_cmd[i] && a->full_cmd[i][0] == '-'
        && a->full_cmd[1][j] == 'n')
        j++;
    if (a->full_cmd[1][j] == '\0')
        return (1);
    return (0);
}
void    my_echo(t_command *a)
{
    int i;
    i = 2;
    if (is_flag(a, 1))
    {
        while (is_flag(a, i))
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

void	my_env(void)
{
	int	i;

	i = 0;
	while (g_global.envp[i] && check_equal(g_global.envp[i]))
		printf("%s\n", g_global.envp[i++]);
}

int	my_cd(t_command *a)
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
	if (is_present(g_global.envp, "OLDPWD"))
		del_env("OLDPWD");
	add_env(ft_strjoin(ft_strdup("OLDPWD="), getenv("OLDPWD")));
	if (is_present(g_global.envp, "PWD"))
		del_env("PWD");
	pwd = getwd(NULL);
	add_env(ft_strjoin(ft_strdup("PWD="), pwd));
	free (pwd);
	return (0);
}

void	my_exit(int status)
{
	printf("exit\n");
	//kill(getppid(), 9);
	exit(status);
}