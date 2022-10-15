/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */ 
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:00:08 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 12:59:12 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	init_input(t_input *input, char *line)
{
	input->double_quotes = count_double_marks(line);
	input->single_quotes = count_single_marks(line);
	if (input->double_quotes % 2 != 0 || input->single_quotes % 2 != 0)
		return (printf("Syntax Error: quotes not closed\n"));
	input->line = ft_strdup(line);
	quote_split(input);
	return (0);
}

char	*lexer(char *line)
{
	t_input input;

	if (*line == '\0')
		return (NULL);
	if (init_input(&input, line))
		return (NULL);
	for(int i = 0; input.quotes[i]; i++)
		printf("quotes[%d]:%s\n", i, input.quotes[i]);
	return (line);
}