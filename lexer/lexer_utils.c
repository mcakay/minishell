/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:29:55 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/20 18:21:11 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	is_special_char(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int	is_space_or_null(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	append_str(char *s1, char *s2, int *i, int *j)
{
	s1[*j] = s2[*i];
	(*i)++;
	(*j)++;
}

void	skip_quotes(t_input *input, int *i, char quote)
{
	int		flag;

	flag = 1;
	(*i)++;
	while (input->line[*i] != quote && input->line[*i] != '\0')
		(*i)++;
	if (input->line[*i] == '\0')
		flag = 0;
	while ((is_space_or_null(input->line[*i]) == 0 || flag) && is_special_char(input->line[*i]) == 0)
	{
		if (input->line[*i] == quote)
			flag = !flag;
		(*i)++;
	}
	while (is_space(input->line[*i]) == 1)
		(*i)++;
	input->args_size++;
}