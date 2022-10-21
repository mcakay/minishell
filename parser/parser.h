/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:59 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/21 05:38:26 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

//envp
void	copy_envp(char **envp, t_prompt *prompt);

//cmd
void	get_cmds(t_command **cmds, char **strs);

//path
void	get_path(t_prompt *prompt);

#endif