/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 02:03:13 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 02:54:11 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	get_redirections(t_command *curr)
{
	int		fd;
	if (curr->infile_list)
	{
		while (curr->infile_list->next)
		{
			if (access(curr->infile_list->infile, F_OK) != 0)
			{
				printf("minishell: %s: No such file or directory\n", curr->infile_list->infile);
				g_global.status = 1;
			}
			curr->infile_list = curr->infile_list->next;
		}
		if (access(curr->infile_list->infile, F_OK) != 0)
		{
			printf("minishell: %s: No such file or directory\n", curr->infile_list->infile);
			g_global.status = 1;
		}
		curr->infile = open(curr->infile_list->infile, O_RDONLY, 0777);
	}
	if (curr->outfile_list)
	{
		while (curr->outfile_list->next)
		{
			fd = open(curr->outfile_list->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			curr->outfile_list = curr->outfile_list->next;
			close(fd);
		}
		curr->outfile = open(curr->outfile_list->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
}

int	here_doc(t_command *cmd)
{
	t_here_doc	*curr;
	char		*line;
	char		*buffer;
	curr = cmd->here_doc_list;
	buffer = ft_strdup("");
	g_global.pid = 2;
	while (curr)
	{
		if (g_global.here_doc == 1)
		{
			g_global.pid = 1;
			return (1);
		}
		line = readline("> ");
		if (ft_strcmp(line, curr->here_doc) == 0)
			curr = curr->next;
		else
			get_buffer(&buffer, line);
		free(line);
	}
	cmd->infile = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(cmd->infile, buffer, ft_strlen(buffer));
	close(cmd->infile);
	cmd->infile = open("heredoc", O_RDONLY, 0777);
	free(buffer);
	g_global.pid = 1;
	return (0);
}

void	append_mode(t_command *cmd)
{
	t_append	*curr;
	int				fd;

	curr = cmd->append_list;
	while (curr)
	{
		fd = open(curr->append, O_WRONLY | O_APPEND | O_CREAT, 0777);
		cmd->outfile = fd;
		curr = curr->next;
	}
}

void	close_all_redirections(t_command **cmd)
{
	t_command *curr;
	curr = *cmd;
	while (curr)
	{
		if (curr->infile)
			close(curr->infile);
		if (curr->outfile)
			close(curr->outfile);
		curr = curr->next;
	}
}