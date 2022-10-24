/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_calc_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 05:21:57 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 15:31:06 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	calc_env_size(t_input *input, int i, int k)
{
	char	*str;
	int		j;
	int		l;

	j = 0;
	str = ft_substr(input->line, i - k, k);
	input->dollar_size += ft_strlen(str);
	while (input->envs[j])
	{
		l = 0;
		while (input->envs[j][l] != '=' && input->envs[j][l] != '\0')
			l++;
		if (ft_strncmp(input->envs[j], str, l) == 0)
		{
			input->env_size += ft_strlen(input->envs[j]) - l - 1;
			break ;
		}
		j++;
	}
	free(str);
}

void	calc_size_double_quote(t_input *input, int *i)
{
	int	k;

	k = 0;
	(*i)++;
	while (input->line[*i] != '"' && input->line[*i] != '\0')
	{
		if (input->line[*i] == '$')
		{
			(*i)++;
			while (ft_isalnum(input->line[*i]) == 1)
			{
				(*i)++;
				k++;
			}
			if (k)
				calc_env_size(input, *i, k);
			k = 0;
		}
		else
			(*i)++;
	}
}

void	calc_size(t_input *input, int i, int k)
{
	while (input->line[i])
	{
		if (input->line[i] == '"')
			calc_size_double_quote(input, &i);
		else if (input->line[i] == '\'')
		{
			i++;
			while (input->line[i] != '\'' && input->line[i] != '\0')
				i++;
			if (input->line[i] == '\'')
				i++;
		}
		else if (input->line[i] == '$')
		{
			i++;
			while (ft_isalnum(input->line[i]) == 1)
			{
				i++;
				k++;
			}
			if (k)
				calc_env_size(input, i, k);
			k = 0;
		}
		else
			i++;
	}
}

void	calc_args_size(t_input *input)
{
	int	i;

	i = 0;
	while (input->line[i])
	{
		if (input->line[i] == '"' || input->line[i] == '\'')
			skip_quotes(input, &i, input->line[i]);
		else
		{
			while (is_space(input->line[i]) == 1)
				i++;
			if (input->line[i] != '\0')
				input->args_size++;
			while (is_space_or_null(input->line[i]) == 0)
			{
				if (is_special_char(input->line[i]) == 1)
					input->args_size += 2;
				i++;
			}
		}
	}
}
