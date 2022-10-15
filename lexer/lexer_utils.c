/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:38:46 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 17:37:26 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	is_special_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '>' || str[i] == '<')
			return (1);
		i++;
	}
	return (0);
}

char	*add_marks(char *str)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 1;
	rtn = malloc(sizeof(char) * (ft_strlen(str) + 3));
	rtn[0] = '"';
	while (str[i])
	{
		rtn[j] = str[i];
		j++;
		i++;
	}
	rtn[j] = '"';
	j++;
	rtn[j] = '\0';
	free(str);
	return (rtn);
}