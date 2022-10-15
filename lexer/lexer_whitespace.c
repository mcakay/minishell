/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:57:14 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 03:41:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int calculate_size(char *line)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (line[i])
	{
		while (!is_whitespace(line[i]) && line[i])
		{
			size++;
			i++;
		}
		while (is_whitespace(line[i]))
			i++;
	}
	
	return (size);
}

static int	check_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!is_whitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*remove_whitespaces(char *str)
{
	char	*rtn;
	char	*tmp;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	if (check_empty(str))
	{
		rtn = malloc(sizeof(char) * 2);
		rtn[0] = ' ';
		rtn[1] = '\0';
		return (rtn);
	}
	tmp = ft_strtrim(str, " \t");
	rtn = malloc(sizeof(char) * (calculate_size(str) + 1));
	while (tmp[i])
	{
		if (is_whitespace(tmp[i]))
		{
			rtn[j] = ' ';
			j++;
			while (is_whitespace(tmp[i]))
				i++;
		}
		rtn[j] = tmp[i];
		i++;
		j++;
	}
	free(tmp);
	rtn[j] = '\0';
	return (rtn);
}