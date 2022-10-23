/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:59 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/23 05:57:30 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

//envp
void	copy_envp(char **envp, t_prompt *prompt);

//cmd
void	get_cmds(t_prompt *prompt, t_command **cmds, char **strs);

//path
void	get_path(t_prompt *prompt);

//redirection
int		is_redirection(char *str);
void	add_node_infile(t_infile **root, char *str);
void	add_node_outfile(t_outfile **root, char *str);

//utils
int		ft_strcmp(const char *s1, const char *s2);

#endif