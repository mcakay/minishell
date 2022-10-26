/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:12:46 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/27 01:04:30 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	lexer_add_dollar(t_input *input, char *rtn, int *i, int *k, int *j, char **envp)
{
	char	*str;
	char	*tmp;
	int		a;
	int		l;
	int		b;

	a = 0;
	str = ft_substr(input->line, *i - *k, *k);
	while (envp[a])
	{
		l = 0;
		while (envp[a][l] != '=' && envp[a][l] != '\0')
			l++;
		l++;
		if (ft_strncmp(envp[a], str, l - 1) == 0)
		{
			while (envp[a][l] != '\0')
			{
				rtn[*j] = envp[a][l];
				(*j)++;
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
				rtn[*j] = tmp[b];
				(*j)++;
				b++;
			}
			free(tmp);
			break ;
		}
		a++;
	}
	free(str);
}

void	lexer_add_dollar_double_quotes(t_input *input, char *rtn, int *i, int *k, int *j, char **envp)
{
	append_str(rtn, input->line, i, j);
	while (input->line[*i] != '"' && input->line[*i] != '\0')
	{
		if (input->line[*i] == '$')
		{
			(*i)++;
			while (ft_isalnum(input->line[*i]) == 1 || input->line[*i] == '?')
			{
				(*i)++;
				(*k)++;
			}
			if (*k)
				lexer_add_dollar(input, rtn, i, k, j, envp);
			*k = 0;
		}
		else
			append_str(rtn, input->line, i, j);
	}
}

void	lexer_add_env(t_input *input, char **envp)
{
	char	*rtn;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	rtn = malloc(sizeof(char) * (ft_strlen(input->line) + input->env_size - input->dollar_size + 1));
	while (input->line[i])
	{
		if (input->line[i] == '"')
			lexer_add_dollar_double_quotes(input, rtn, &i, &k, &j, envp);
		else if (input->line[i] == '$')
		{
			i++;
			while (ft_isalnum(input->line[i]) == 1 || input->line[i] == '?')
			{
				i++;
				k++;
			}
			if (k)
				lexer_add_dollar(input, rtn, &i, &k, &j, envp);
			k = 0;
		}
		else if (input->line[i] == '\'')
		{
			append_str(rtn, input->line, &i, &j);
			while (input->line[i] != '\'')
				append_str(rtn, input->line, &i, &j);
			append_str(rtn, input->line, &i, &j);
		}
		else
			append_str(rtn, input->line, &i, &j);
	}
	rtn[j] = '\0';
	free(input->line);
	input->line = rtn;
}