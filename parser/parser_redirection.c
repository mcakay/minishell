/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:27:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/23 23:21:25 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_redirection(char *str)
{
	if (ft_strcmp(str, ">") == 0)
		return (1);
	else if (ft_strcmp(str, "<") == 0)
		return (2);
	else if (ft_strcmp(str, ">>") == 0)
		return (3);
	else if (ft_strcmp(str, "<<") == 0)
		return (4);
	else
		return (0);
}

void	handle_redirections(t_command *command, char **strs, int *i)
{
	if (is_redirection(strs[*i]) == 1)
	{
		add_node_outfile(&command->outfile_list, strs[*i + 1]);
		*i += 2;
	}
	else if (is_redirection(strs[*i]) == 2)
	{
		add_node_infile(&command->infile_list, strs[*i + 1]);
		*i += 2;
	}
}

void	init_redirections(t_command **cmd, char **strs)
{
	t_command *curr;
	int		i;

	curr = *cmd;
	i = 0;
	while (curr && strs[i])
	{
		if (is_redirection(strs[i]))
			handle_redirections(curr, strs, &i);
		else if (strs[i][0] == '|')
		{
			curr = curr->next;
			i++;
		}
		else
			i++;
	}
}