/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_calc_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 05:21:57 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 06:08:26 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	calc_env_size(t_input *input)
{
	char	*str;
	int		j;
	int		l;

	j = 0;
	str = ft_substr(input->line, input->i - input->k, input->k);
	input->dollar_size += ft_strlen(str) + 1;
	while (g_global.envp[j])
	{
		l = 0;
		while (g_global.envp[j][l] != '=' && g_global.envp[j][l] != '\0')
			l++;
		if (ft_strncmp(g_global.envp[j], str, l) == 0)
		{
			input->env_size += ft_strlen(g_global.envp[j]) - l - 1;
			break ;
		}
		else if (str[0] == '?' && str[1] == '\0')
		{
			if_question_mark2(input);
			break ;
		}
		j++;
	}
	free(str);
}

void	calc_size_double_quote(t_input *input)
{
	input->i++;
	while (input->line[input->i] != '"' && input->line[input->i] != '\0')
	{
		if (input->line[input->i] == '$')
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
		else
			input->i++;
	}
}

void	calc_size(t_input *input)
{
	while (input->line[input->i])
	{
		if (input->line[input->i] == '"')
			calc_size_double_quote(input);
		else if (input->line[input->i] == '\'')
		{
			input->i++;
			while (input->line[input->i] != '\''
				&& input->line[input->i] != '\0')
				input->i++;
			if (input->line[input->i] == '\'')
				input->i++;
		}
		else if (input->line[input->i] == '$')
			if_dollar(input);
		else
			input->i++;
	}
}

void	calc_args_size(t_input *input)
{
	while (input->line[input->i])
	{
		if (input->line[input->i] == '"' || input->line[input->i] == '\'')
			skip_quotes(input, input->line[input->i]);
		else
		{
			while (is_space(input->line[input->i]) == 1)
				input->i++;
			if (input->line[input->i] != '\0')
				input->args_size++;
			while (is_space_or_null(input->line[input->i]) == 0)
			{
				if (is_special_char(input->line[input->i]) == 1)
					input->args_size += 2;
				input->i++;
			}
		}
	}
}
