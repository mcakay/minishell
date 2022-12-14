/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:27:33 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 06:53:49 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../minishell.h"
# include <fcntl.h>

//access
char	*access_check(char **path, char *cmd);
void	add_path_to_cmds(t_prompt *prompt);
void	init_pipes(t_prompt *prompt);

//builtin
int		is_builtin1(char *cmd);
int		is_builtin2(char *cmd);
void	exec_builtin1(t_command *cmd);
void	exec_builtin2(t_command *cmd);

//redirections
void	get_redirections(t_command *curr);
void	close_all_redirections(t_command **cmd);
int		here_doc(t_command *cmd);
void	append_mode(t_command *cmd);

//utils
void	get_buffer(char **buffer, char *line);
int		is_redirection_exec(t_command *cmd);
void	close_all(t_prompt *parsed);
void	close_all_pipes(t_prompt *prompt);
void	wait_cmd(t_prompt *prompt);

#endif