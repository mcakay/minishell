/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:05:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 15:26:41 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	quote_open(t_input *input, int *j, int *i, char quote)
{
	int		k;
	int		flag;

	flag = 1;
	k = 0;
	(*i)++;
	while (input->line[*i + k] != quote && input->line[*i + k] != '\0')
		k++;
	if (input->line[*i + k] == '\0')
		flag = 0;
	while ((is_space_or_null(input->line[*i + k]) == 0 || flag)
		&& is_special_char(input->line[*i + k]) == 0)
	{
		if (input->line[*i + k] == quote)
			flag = !flag;
		k++;
	}
	input->args[*j] = ft_substr(input->line, *i - 1, k + 1);
	while (is_space(input->line[*i + k]) == 1)
		k++;
	*i += k;
	(*j)++;
}

int	quote_out_two(t_input *input, int *i)
{
	int	k;
	int	flag;
	int	mark;

	flag = 0;
	mark = 0;
	k = 0;
	while ((is_space_or_null(input->line[*i + k]) == 0 || flag)
		&& (is_special_char(input->line[*i + k]) == 0 || flag))
	{
		if ((input->line[*i + k] == '"' || input->line[*i + k] == '\'')
			&& !mark)
		{
				mark = input->line[*i + k];
				flag = !flag;
		}
		else if (mark && input->line[*i + k] == mark)
		{
			flag = !flag;
			mark = 0;
		}
		k++;
	}
	return (k);
}

void	quote_out(t_input *input, int *j, int *i)
{
	int		k;

	while (is_space (input->line[*i]) == 1)
		(*i)++;
	k = quote_out_two(input, i);
	input->args[*j] = ft_substr(input->line, *i, k);
	while (is_space(input->line[*i + k]) == 1)
		k++;
	*i += k;
	(*j)++;
}

void	special_char(t_input *input, int *j, int *i)
{
	int		k;

	k = 0;
	(*i)++;
	while (is_space_or_null(input->line[*i + k]) == 0)
	{
		if (input->line[*i + k] != input->line[*i - 1]
			|| (input->line[*i + k] != '<' && input->line[*i + k] != '>')
			|| k != 0)
			break ;
		else
			k++;
	}
	input->args[*j] = ft_substr(input->line, *i - 1, k + 1);
	while (is_space(input->line[*i + k]) == 1)
		k++;
	*i += k;
	(*j)++;
}

void	quote_split(t_input *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	input->args = malloc(sizeof(char *) * (input->args_size + 1));
	printf("input->line: |%s|\n", input->line);
	while (input->line[i])
	{
		if (input->line[i] == '"' || input->line[i] == '\'')
			quote_open(input, &j, &i, input->line[i]);
		else if (is_special_char(input->line[i]) == 1)
			special_char(input, &j, &i);
		else
			quote_out(input, &j, &i);
	}
	input->args[j] = NULL;
}
