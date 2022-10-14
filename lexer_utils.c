/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:05:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/14 18:08:11 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

void	quote_in_split(t_input *input, char *line)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	input->quotes_in = malloc(sizeof(char *) * (input->double_quotes / 2 + 1));
	while (line[i])
	{
		k = 0;
		if (line[i] == '"')
		{
			i++;
			while (line[i + k] != '"' && line[i + k])
				k++;
			input->quotes_in[j] = ft_substr(line, i, k);
			j++;
			i += k;
		}
		i++;
	}
	input->quotes_in[j] = NULL;
}

void	quote_out_split(t_input *input, char *line)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	input->quotes_out = malloc(sizeof(char *) * (input->double_quotes / 2 + 1));
	while (line[i])
	{
		k = 0;
		if (line[i] == '"')
		{
			i++;
			while (line[i] != '"' && line[i])
				i++;
			i++;
			while (line[i + k] != '"' && line[i + k])
				k++;
			input->quotes_out[j] = ft_substr(line, i, k);
			j++;
			i += k;
		}
		else
		{
			while (line[i + k] != '"' && line[i + k])
				k++;
			input->quotes_out[j] = ft_substr(line, i, k);
			j++;
			i += k;
		}
	}
	input->quotes_out[j] = NULL;
}