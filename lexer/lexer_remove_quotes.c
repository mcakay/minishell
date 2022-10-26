/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:31:02 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/26 13:42:36 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
	j = 0;
	rtn = malloc(sizeof(char) * (ft_strlen(str) - calc_size_remove_quotes(str) + 1));
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