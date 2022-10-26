/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:59 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/26 16:16:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

//cmd
int		get_cmds(t_command **cmds, char **strs);

//path
void	get_path(t_prompt *prompt);

//redirection
int		is_redirection(char *str);
void	add_node_infile(t_infile **root, char *str);
void	add_node_outfile(t_outfile **root, char *str);
void	handle_redirections(t_command *command, char **strs, int *i);
void	init_redirections(t_command **cmd, char **strs);

#endif