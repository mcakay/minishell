/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:45:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 05:25:37 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_command(t_command *tmp)
{
	int			i;
	t_command	*tmp2;

	while (tmp)
	{
		i = 0;
		tmp2 = tmp->next;
		if (tmp->full_path)
			free(tmp->full_path);
		if (tmp->full_cmd)
		{
			while (tmp->full_cmd[i])
			{
				free(tmp->full_cmd[i]);
				i++;
			}
			free(tmp->full_cmd);
		}
		free_redirections(tmp);
		free(tmp);
		tmp = tmp2;
	}
}

void	free_parsed(t_prompt *prompt)
{
	t_command	*tmp;
	int			i;

	tmp = prompt->cmds;
	i = 0;
	if (prompt->path)
	{
		while (prompt->path[i])
		{	
			free(prompt->path[i]);
			i++;
		}
		free(prompt->path);
	}
	free(prompt);
}
