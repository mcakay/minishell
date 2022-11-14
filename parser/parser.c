/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 03:19:41 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

int	init_prompt(t_prompt *prompt, char **strs)
{
	t_command	*cmds;

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
	t_command	*curr;
	t_input		*input;
	int			i;

	input = malloc(sizeof(t_input));
	prompt = malloc(sizeof(t_prompt));
	if (init_prompt(prompt, strs))
		return (NULL);
	curr = prompt->cmds;
	while (curr)
	{
		i = 0;
		while (curr->full_cmd[i])
		{
			reset_iters(input);
			curr->full_cmd[i] = remove_quotes(curr->full_cmd[i], input);
			i++;
		}
		curr = curr->next;
	}
	free(input);
	return (prompt);
}
