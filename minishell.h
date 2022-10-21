/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:10:45 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/21 06:11:10 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL

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