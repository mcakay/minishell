/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:27:33 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/29 03:50:28 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../minishell.h"

//access
char 	*access_check(char **path, char *cmd);
int		add_path_to_cmds(t_prompt *prompt);
void	init_pipes(t_prompt *prompt);

//builtin
int		is_builtin(char *cmd);
void	exec_builtin(t_command *cmd);

//redirections
int		get_redirections(t_command **cmd);

#endif