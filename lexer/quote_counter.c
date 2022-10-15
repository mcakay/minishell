/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:59:15 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 00:00:49 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	count_double_marks(char *line)
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

int count_single_marks(char *line)
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
		i++;
		while (line[i] != '"' && line[i] != '\0')
			i++;
		i++;
	}
	return (count);
}