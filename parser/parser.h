/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:02:15 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/18 15:36:41 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
	struct s_mini *next;
}				t_mini;

typedef struct s_prompt
{
	t_mini	*cmds;
	char	**envp;
	pid_t	pid;
}				t_prompt;

//envp
void	copy_envp(char **envp, t_prompt *prompt);

//cmd
void	get_cmds(t_mini **cmds, char **strs);

#endif