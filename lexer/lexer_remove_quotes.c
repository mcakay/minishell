/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:31:02 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 03:20:29 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	calc_size_remove_quotes(char *str, t_input *input)
{
	int		size;
	char	mark;

	size = 0;
	while (str[input->i])
	{
		if (str[input->i] == '"' || str[input->i] == '\'')
		{
			mark = str[input->i];
			input->i++;
			size++;
			while (str[input->i] != mark && str[input->i])
				input->i++;
			input->i++;
			size++;
		}
		else
			input->i++;
	}
	return (size);
}

char	*remove_quotes(char *str, t_input *input)
{
	char	*rtn;
	char	mark;

	rtn = malloc(sizeof(char) * (ft_strlen(str) - calc_size_remove_quotes(str,
					input) + 1));
	reset_iters(input);
	while (str[input->i])
	{
		if (str[input->i] == '"' || str[input->i] == '\'')
		{
			g_global.quotes++;
			mark = str[input->i];
			input->i++;
			while (str[input->i] != mark && str[input->i])
				append_str(rtn, str, input);
			input->i++;
		}
		else
			append_str(rtn, str, input);
	}
	rtn[input->j] = '\0';
	free(str);
	return (rtn);
}
