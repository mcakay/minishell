/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:10:45 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/22 14:42:05 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include "./libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_command
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
	int		fd[2];
	struct s_command *next;
	struct s_command *prev;
}				t_command;

typedef struct s_prompt
{
	t_command	*cmds;
	char		**envp;
	char		**path;
	pid_t		pid;
}				t_prompt;

//lexer
char		**lexer(char *line, char **envp);
t_prompt	parser(char **strs, char **envp);
void		executor(t_prompt parsed);
#endif