/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:31:04 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 06:55:31 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	get_buffer(char **buffer, char *line)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(*buffer, line);
	tmp2 = ft_strjoin(tmp, "\n");
	free(tmp);
	free(*buffer);
	*buffer = ft_strdup(tmp2);
	free(tmp2);
}

void	close_all_redirections(t_command **cmd)
{
	t_command	*curr;

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

int	is_redirection_exec(t_command *cmd)
{
	if (cmd->infile_list || cmd->outfile_list
		|| cmd->here_doc_list || cmd->append_list)
		return (1);
	return (0);
}

void	close_all(t_prompt *parsed)
{
	wait_cmd(parsed);
	close_all_pipes(parsed);
	close_all_redirections(&parsed->cmds);
}
