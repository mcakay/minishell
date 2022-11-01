/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote_counter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:59:15 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/01 14:51:39 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	count_double_quotes(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '"')
			count++;
		i++;
	}
	return (count);
}

int count_single_quotes(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] != '"' && line[i] != '\0')
		{
			if (line[i] == '\'')
				count++;
			i++;
		}
		if (line[i])
			i++;
		while (line[i] != '"' && line[i] != '\0')
			i++;
		if (line[i])
			i++;
	}
	return (count);
}