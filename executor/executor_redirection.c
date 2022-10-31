/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 02:03:13 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/30 22:33:38 by mcakay           ###   ########.fr       */
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
				if (access(curr->infile_list->infile, F_OK) != 0)
					return (printf("minishell: %s: No such file or directory\n", curr->infile_list->infile));	
				curr->infile_list = curr->infile_list->next;
			}
			if (access(curr->infile_list->infile, F_OK) != 0)
					return (printf("minishell: %s: No such file or directory\n", curr->infile_list->infile));
			curr->infile = open(curr->infile_list->infile, O_RDONLY, 0777);
		}
		if (curr->outfile_list)
		{
			while (curr->outfile_list->next)
			{
				open(curr->outfile_list->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
				curr->outfile_list = curr->outfile_list->next;
			}
			curr->outfile = open(curr->outfile_list->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		}
		curr = curr->next;
	}
	return (0);
}