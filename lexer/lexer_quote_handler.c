/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:05:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 06:18:19 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	quote_open(t_input *input, char quote)
{
	int		k;
	int		flag;

	flag = 1;
	k = 0;
	input->i++;
	while (input->line[input->i + k] != quote
		&& input->line[input->i + k] != '\0')
		k++;
	if (input->line[input->i + k] == '\0')
		flag = 0;
	while ((is_space_or_null(input->line[input->i + k]) == 0 || flag)
		&& is_special_char(input->line[input->i + k]) == 0)
	{
		if (input->line[input->i + k] == quote)
			flag = !flag;
		k++;
	}
	input->args[input->j] = ft_substr(input->line, input->i - 1, k + 1);
	while (is_space(input->line[input->i + k]) == 1)
		k++;
	input->i += k;
	input->j++;
}

void	quote_out_util(t_input *input, int *k, int *flag, char *mark)
{
	if ((input->line[input->i + *k] == '"'
			|| input->line[input->i + *k] == '\'') && !(*mark))
	{
		*mark = input->line[input->i + *k];
		*flag = !(*flag);
	}
	else if (mark && input->line[input->i + *k] == *mark)
	{
		*flag = !(*flag);
		*mark = 0;
	}
	(*k)++;
}

void	quote_out(t_input *input)
{
	int		k;
	int		flag;
	char	mark;

	flag = 0;
	k = 0;
	mark = 0;
	while (is_space(input->line[input->i]) == 1)
		input->i++;
	while ((is_space_or_null(input->line[input->i + k]) == 0 || flag)
		&& (is_special_char(input->line[input->i + k]) == 0 || flag))
		quote_out_util(input, &k, &flag, &mark);
	input->args[input->j] = ft_substr(input->line, input->i, k);
	while (is_space(input->line[input->i + k]) == 1)
		k++;
	input->i += k;
	input->j++;
}

void	special_char(t_input *input)
{
	int		k;

	k = 0;
	input->i++;
	while (is_space_or_null(input->line[input->i + k]) == 0)
	{
		if (input->line[input->i + k] != input->line[input->i - 1]
			|| (input->line[input->i + k] != '<'
				&& input->line[input->i + k] != '>')
			|| k != 0)
			break ;
		else
			k++;
	}
	input->args[input->j] = ft_substr(input->line, input->i - 1, k + 1);
	while (is_space(input->line[input->i + k]) == 1)
		k++;
	input->i += k;
	input->j++;
}

void	quote_split(t_input *input)
{
	input->args = malloc(sizeof(char *) * (input->args_size + 1));
	while (input->line[input->i])
	{
		if (input->line[input->i] == '"' || input->line[input->i] == '\'')
			quote_open(input, input->line[input->i]);
		else if (is_special_char(input->line[input->i]) == 1)
			special_char(input);
		else
			quote_out(input);
	}
	input->args[input->j] = NULL;
}
