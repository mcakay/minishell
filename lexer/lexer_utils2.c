/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 04:36:05 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 06:22:40 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	skip_quotes(t_input *input, char quote)
{
	int		flag;

	flag = 1;
	input->i++;
	while (input->line[input->i] != quote && input->line[input->i] != '\0')
		input->i++;
	if (input->line[input->i] == '\0')
		flag = 0;
	while ((is_space_or_null(input->line[input->i]) == 0 || flag)
		&& is_special_char(input->line[input->i]) == 0)
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

void	if_question_mark(t_input *input, char *rtn)
{
	char	*tmp;

	input->b = 0;
	tmp = ft_itoa(g_global.status);
	while (tmp[input->b] != '\0')
	{
		rtn[input->j] = tmp[input->b];
		input->j++;
		input->b++;
	}
	free(tmp);
}

void	skip_path(t_input *input)
{
	input->l = 0;
	while (g_global.envp[input->a][input->l] != '='
		&& g_global.envp[input->a][input->l] != '\0')
			input->l++;
	input->l++;
}

void	get_env_name(t_input *input, char *rtn)
{
	input->i++;
	while (ft_isalnum(input->line[input->i]) == 1
		|| input->line[input->i] == '?')
	{
		input->i++;
		input->k++;
	}
	if (input->k)
		lexer_add_dollar(input, rtn);
	input->k = 0;
}

void	if_dollar(t_input *input)
{
	input->i++;
	while (ft_isalnum(input->line[input->i]) == 1
		|| input->line[input->i] == '?')
	{
		input->i++;
		input->k++;
	}
	if (input->k)
		calc_env_size(input);
	input->k = 0;
}
