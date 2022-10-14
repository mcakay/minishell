/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:00:08 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 00:38:07 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	init_input(t_input *input, char *line)
{
	input->double_quotes = count_double_marks(line);
	input->single_quotes = count_single_marks(line);
	printf("single quotes: %d\n", input->single_quotes);
	if (input->double_quotes % 2 != 0 || input->single_quotes % 2 != 0)
		return (printf("Syntax Error: quotes not closed\n"));
	input->line = ft_strdup(line);
	quote_split(input);
	return (0);
}

char	*merge(t_input *input)
{
	char	*rtn;
	char	*tmp;
	int		i;

	i = 2;
	tmp = ft_strdup(input->quotes[0]);
	rtn = ft_strjoin(tmp, input->quotes[1]);
	while (input->quotes[i])
	{
		free(tmp);
		tmp = ft_strjoin(rtn, input->quotes[i]);
		free(rtn);
		rtn = ft_strdup(tmp);
		i++;
	}
	return (rtn);
}

char	*lexer(char *line)
{
	t_input input;

	if (init_input(&input, line))
		return (NULL);
	for (int i = 0; input.quotes[i]; i++)
		printf("%s\n", input.quotes[i]);
	printf("merged: %s\n", merge(&input));
	return (line);
}