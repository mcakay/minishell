/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:29:55 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/27 18:48:53 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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

void	append_str(char *s1, char *str, t_input *input)
{
	s1[input->j] = str[input->i];
	input->i++;
	input->j++;
}

void	skip_quotes(t_input *input, char quote)
{
	int		flag;

	flag = 1;
	input->i++;
	while (input->line[input->i] != quote && input->line[input->i] != '\0')
		input->i++;
	if (input->line[input->i] == '\0')
		flag = 0;
	while ((is_space_or_null(input->line[input->i]) == 0 || flag) && is_special_char(input->line[input->i]) == 0)
	{
		if (input->line[input->i] == quote)
			flag = !flag;
		else if (!flag && is_special_char(input->line[input->i]))
			input->args_size++;
		input->i++;
	}
	while (is_space(input->line[input->i]) == 1)
		input->i++;
	input->args_size++;
}

void	reset_iters(t_input *input)
{
	input->i = 0;
	input->j = 0;
	input->k = 0;
}