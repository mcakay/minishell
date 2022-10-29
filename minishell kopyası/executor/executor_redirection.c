/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 02:03:13 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/29 06:24:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	get_redirections(t_command **cmd)
{
	t_command *curr;
	curr = *cmd;
	while (curr)
	{
		if (curr->infile_list)
		{
			while (curr->infile_list->next)
			{
				if (access(curr->infile_list->infile, X_OK) != 0)
					return (printf("minishell: %s: No such file or directory\n", curr->infile_list->infile));	
				curr->infile_list = curr->infile_list->next;
			}
			if (curr->infile_list && access(curr->infile_list->infile, X_OK) != 0)
					return (printf("minishell: %s: No such file or directory\n", curr->infile_list->infile));
			curr->infile = curr->infile_list->infile;
		}
		if (curr->outfile_list)
		{
			while (curr->outfile_list->next)
				curr->outfile_list = curr->outfile_list->next;
		}
		if (curr->outfile_list)
			curr->outfile = curr->outfile_list->outfile;
		curr = curr->next;
	}
	return (0);
}