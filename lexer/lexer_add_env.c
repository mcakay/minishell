/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:12:46 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 06:22:20 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	lexer_add_dollar(t_input *input, char *rtn)
{
	char	*str;

	str = ft_substr(input->line, input->i - input->k, input->k);
	while (g_global.envp[input->a])
	{
		skip_path(input);
		if (ft_strncmp(g_global.envp[input->a], str, input->l - 1) == 0)
		{
			while (g_global.envp[input->a][input->l] != '\0')
			{
				rtn[input->j] = g_global.envp[input->a][input->l];
				input->j++;
				input->l++;
			}
			break ;
		}
		else if (str[0] == '?' && str[1] == '\0')
		{
			if_question_mark(input, rtn);
			break ;
		}
		input->a++;
	}
	free(str);
}

void	lexer_add_dollar_double_quotes(t_input *input, char *rtn)
{
	append_str(rtn, input->line, input);
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
				lexer_add_dollar(input, rtn);
			input->k = 0;
		}
		else
			append_str(rtn, input->line, input);
	}
}

void	lexer_add_env(t_input *input)
{
	char	*rtn;

	rtn = malloc(sizeof(char) * (ft_strlen(
					input->line) + input->env_size - input->dollar_size + 1));
	while (input->line[input->i])
	{
		if (input->line[input->i] == '"')
			lexer_add_dollar_double_quotes(input, rtn);
		else if (input->line[input->i] == '$')
			get_env_name(input, rtn);
		else if (input->line[input->i] == '\'')
		{
			append_str(rtn, input->line, input);
			while (input->line[input->i] != '\'')
				append_str(rtn, input->line, input);
			append_str(rtn, input->line, input);
		}
		else
			append_str(rtn, input->line, input);
	}
	rtn[input->j] = '\0';
	free(input->line);
	input->line = rtn;
}
