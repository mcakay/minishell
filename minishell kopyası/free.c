/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:45:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/28 23:27:45 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strs(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_parsed(t_prompt *prompt)
{
	t_command *curr;
	t_command *temp;
	t_outfile *out_curr;
	t_outfile *out_temp;

	curr = prompt->cmds;
	while (curr)
	{
		temp = curr->next;
		out_curr = curr->outfile_list;
		while (out_curr)
		{
			out_temp = out_curr->next;
			free(out_curr->outfile);
			free(out_curr);
			out_curr = out_temp;
		}
		free(curr);
		curr = temp;
	}

}