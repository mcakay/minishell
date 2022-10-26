/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:10:45 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/26 17:59:43 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "redirection.h"
#include "./libft/libft.h"

typedef struct s_global
{
	int		status;
	char	**envp;
}				t_global;

t_global	g_global;

typedef struct s_command
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
	int		fd[2];
	struct s_command *next;
	struct s_command *prev;
	t_infile *infile_list;
	t_outfile *outfile_list;
	int		pid;
}				t_command;

typedef struct s_prompt
{
	t_command	*cmds;
	char		**path;
	char		**envp;
}				t_prompt;

//lexer
char		**lexer(char *line, char **envp);
t_prompt	*parser(char **strs, char **envp);
void		executor(t_prompt parsed);

//free
void	free_strs(char **strs);

//envp
char	**copy_env(char **envp);
#endif