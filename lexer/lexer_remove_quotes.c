/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:31:02 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/17 03:36:20 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	char	*rtn;
	char	mark;

	i = 0;
	j = 0;
	rtn = malloc(sizeof(char) * 300);
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			mark = str[i];
			i++;
			while (str[i] != mark)
			{
				rtn[j] = str[i];
				i++;
				j++;
			}
			i++;
		}
		else
		{
			rtn[j] = str[i];
			i++;
			j++;
		}
	}
	rtn[j] = '\0';
	free(str);
	return (rtn);
}