/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:10:07 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/28 21:41:58 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "../builtin/builtin.h"

int is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0
	|| ft_strcmp(cmd, "echo") == 0
	|| ft_strcmp(cmd, "pwd") == 0
	|| ft_strcmp(cmd, "exit") == 0
	|| ft_strcmp(cmd, "unset") == 0
	|| ft_strcmp(cmd, "export") == 0
	|| ft_strcmp(cmd, "env") == 0)
		return (1);
	return (0);
}

void	exec_builtin(t_command *cmd)
{
	if (ft_strcmp(cmd->full_cmd[0], "cd") == 0)
		my_cd(cmd);
	else if (ft_strcmp(cmd->full_cmd[0], "echo") == 0)
		my_echo(cmd);
	else if (ft_strcmp(cmd->full_cmd[0], "pwd") == 0)
		my_pwd();
	else if (ft_strcmp(cmd->full_cmd[0], "exit") == 0)
		my_exit(ft_atoi(cmd->full_cmd[1]));
	else if (ft_strcmp(cmd->full_cmd[0], "unset") == 0)
		my_unset(cmd);
	else if (ft_strcmp(cmd->full_cmd[0], "export") == 0)
		my_export(cmd);
	else if (ft_strcmp(cmd->full_cmd[0], "env") == 0)
		my_env();
}