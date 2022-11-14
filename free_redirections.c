/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 04:01:50 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 06:22:54 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_infile_list(t_command *cmd)
{
	t_infile	*tmp;
	t_infile	*tmp2;

	tmp = cmd->infile_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		free(tmp->infile);
		tmp = tmp2;
	}
}

void	free_outfile_list(t_command *cmd)
{
	t_outfile	*tmp;
	t_outfile	*tmp2;

	tmp = cmd->outfile_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		free(tmp->outfile);
		tmp = tmp2;
	}
}

void	free_append(t_command *cmd)
{
	t_append	*tmp;
	t_append	*tmp2;

	tmp = cmd->append_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		free(tmp->append);
		tmp = tmp2;
	}
}

void	free_here_doc(t_command *cmd)
{
	t_here_doc	*tmp;
	t_here_doc	*tmp2;

	tmp = cmd->here_doc_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		free(tmp->here_doc);
		tmp = tmp2;
	}
}

void	free_redirections(t_command *cmd)
{
	if (cmd->infile_list)
		free_infile_list(cmd);
	if (cmd->outfile_list)
		free_outfile_list(cmd);
	if (cmd->append_list)
		free_append(cmd);
	if (cmd->here_doc_list)
		free_here_doc(cmd);
}
