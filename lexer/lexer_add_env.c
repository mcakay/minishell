/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:12:46 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/02 02:16:21 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	lexer_add_dollar(t_input *input, char *rtn)
{
	char	*str;
	char	*tmp;
	int		a;
	int		l;
	int		b;

	a = 0;
	str = ft_substr(input->line, input->i - input->k, input->k);
	while (g_global.envp[a])
	{
		l = 0;
		while (g_global.envp[a][l] != '=' && g_global.envp[a][l] != '\0')
			l++;
		l++;
		if (ft_strncmp(g_global.envp[a], str, l - 1) == 0)
		{
			while (g_global.envp[a][l] != '\0')
			{
				rtn[input->j] = g_global.envp[a][l];
				input->j++;
				l++;
			}
			break ;
		}
		else if (str[0] == '?' && str[1] == '\0')
		{
			b = 0;
			tmp = ft_itoa(g_global.status);
			while (tmp[b] != '\0')
			{
				rtn[input->j] = tmp[b];
				input->j++;
				b++;
			}
			free(tmp);
			break ;
		}
		a++;
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
			while (ft_isalnum(input->line[input->i]) == 1 || input->line[input->i] == '?')
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

	rtn = malloc(sizeof(char) * (ft_strlen(input->line) + input->env_size - input->dollar_size + 1));
	while (input->line[input->i])
	{
		if (input->line[input->i] == '"')
			lexer_add_dollar_double_quotes(input, rtn);
		else if (input->line[input->i] == '$')
		{
			input->i++;
			while (ft_isalnum(input->line[input->i]) == 1 || input->line[input->i] == '?')
			{
				input->i++;
				input->k++;
			}
			if (input->k)
				lexer_add_dollar(input, rtn);
			input->k = 0;
		}
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