/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:10:45 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/02 02:17:33 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "redirection.h"
#include "./libft/libft.h"
#include <signal.h>
#include <sys/ioctl.h>

typedef struct s_global
{
	int		status;
	char	**envp;
	int		check;

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
	t_here_doc *here_doc_list;
	t_append *append_list;
	int		pid;
}				t_command;

typedef struct s_prompt
{
	t_command	*cmds;
	char		**path;
}				t_prompt;

//lexer
char		**lexer(char *line);
t_prompt	*parser(char **strs);
void		executor(t_prompt parsed);

//free
void	free_strs(char **strs);
void	free_parsed(t_prompt *prompt);

//envp
char	**copy_env(char **envp);

//signal
void	ctrl_d(void);
void	sigint_handler(int sig);
void	sigquit_handler_in_process(int sig);

#endif