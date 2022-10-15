/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:05:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 18:44:41 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	quote_open(t_input *input, int *j, int *i, char quote)
{
	int		k;

	k = 0;
	(*i)++;
	while (input->line[*i + k] != quote && input->line[*i + k] != '\0')
		k++;
	input->quotes[*j] = ft_substr(input->line, *i, k);
	input->quotes[*j] = add_marks(input->quotes[*j]);
	*i += k + 1;
	(*j)++;
}

void	quote_out(t_input *input, int *j, int *i)
{
	int		k;

	k = 0;
	while (input->line[*i + k] != '"' && input->line[*i + k] != '\'' && input->line[*i + k] != '\0')
		k++;
	input->quotes[*j] = ft_substr(input->line, *i, k);
	input->quotes[*j] = remove_whitespaces(input->quotes[*j]);
	*i += k;
	(*j)++;
}

void	quote_split(t_input *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	input->quotes = malloc(sizeof(char *) * (100000));
	while (input->line[i])
	{
		if (input->line[i] == '"' || input->line[i] == '\'')
			quote_open(input, &j, &i, input->line[i]);
		else
			quote_out(input, &j, &i);
	}
	input->quotes[j] = NULL;
}
