/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:00:08 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/14 23:28:51 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

int	count_marks(char *line, char mark)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == mark)
			count++;
		i++;
	}
	return (count);
}

int	init_input(t_input *input, char *line)
{
	input->double_quotes = count_marks(line, '"');
	input->single_quotes = count_marks(line, '\'');
	if (input->double_quotes % 2 != 0 || input->single_quotes % 2 != 0)
		return (printf("Syntax Error: quotes not closed\n"));
	input->line = ft_strdup(line);
	quote_split(input);
	return (0);
}

char	*lexer(char *line)
{
	t_input input;

	if (init_input(&input, line))
		return (NULL);
	for (int i = 0; input.quotes[i]; i++)
		printf("%s\n", input.quotes[i]);
	return (line);
}