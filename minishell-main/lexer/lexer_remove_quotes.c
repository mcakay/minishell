/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:31:02 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 15:26:18 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	calc_size_remove_quotes(char *str)
{
	int		i;
	int		size;
	char	mark;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			mark = str[i];
			i++;
			size++;
			while (str[i] != mark && str[i])
				i++;
			i++;
			size++;
		}
		else
			i++;
	}
	return (size);
}

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	char	*rtn;
	char	mark;

	i = 0;
	j = calc_size_remove_quotes(str);
	rtn = malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			mark = str[i];
			i++;
			while (str[i] != mark && str[i])
				append_str(rtn, str, &i, &j);
			i++;
		}
		else
			append_str(rtn, str, &i, &j);
	}
	rtn[j] = '\0';
	free(str);
	return (rtn);
}
