/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:57:14 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 18:45:52 by mcakay           ###   ########.fr       */
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

char	*remove_whitespaces(char *str)
{
	char	*rtn;
	char	*tmp;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	rtn = malloc(sizeof(char) * (calculate_size(str) + 20));
	while (str[i])
	{
		if (is_whitespace(str[i]))
		{
			rtn[j] = ' ';
			j++;
			while (is_whitespace(str[i]))
				i++;
		}
		rtn[j] = str[i];
		i++;
		j++;
	}
	rtn[j] = '\0';
	free(str);
	tmp = ft_strtrim(rtn, " \t");
	free(rtn);
	return (tmp);
}