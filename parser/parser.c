/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/02 02:17:25 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	init_prompt(t_prompt *prompt, char **strs)
{
	t_command *cmds;

	cmds = NULL;
	if (get_cmds(&cmds, strs))
		return (1);
	init_redirections(&cmds, strs);
	get_path(prompt);
	prompt->cmds = cmds;
	return (0);
}

t_prompt	*parser(char **strs)
{
	t_prompt	*prompt;

	prompt = malloc(sizeof(t_prompt));
	if (init_prompt(prompt, strs))
		return (NULL);
	return (prompt);
}