/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:27:33 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 14:47:54 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../minishell.h"

//access
char	*access_check(char **path, char *cmd);
int		add_path_to_cmds(t_prompt *prompt);
void	init_pipes(t_prompt *prompt);

#endif