/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_envs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:44:16 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 15:47:05 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	init_envs(t_input *input, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	input->envs = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		input->envs[i] = ft_strdup(envp[i]);
		i++;
	}
	input->envs[i] = NULL;
}

int	add_env(t_input *input, char *rtn, int *i, int *j)
{
	int	l;
	int	s;
	int	k;

	k = 0;
	l = 0;
	s = 0;
	(*i)++;
	while (ft_isalnum(input->line[*i + k]) == 1)
			k++;
	while (input->envs[l])
	{
		s = 0;
		while (input->envs[l][s] != '=' && input->envs[l][s] != '\0')
			s++;
		s++;
		if (ft_strncmp(input->envs[l], input->line + *i, s - 1) == 0
			&& k == s - 1)
		{
			while (input->envs[l][s] != '\0')
				rtn[(*j)++] = input->envs[l][s++];
		}
		l++;
	}
	return (k);
}

void	add_env_double_quote(t_input *input, char *rtn, int *i, int *j)
{
	append_str (rtn, input->line, i, j);
	while (input->line[*i] != '"' && input->line[*i] != '\0')
	{
		if (input->line[*i] == '$')
			(*i) += add_env(input, rtn, i, j);
		else
			append_str(rtn, input->line, i, j);
	}
}

void	init_dollar(t_input *input)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (input->env_size)
		rtn = malloc(sizeof(char) * (ft_strlen(input->line) - input->dollar_size + input->env_size + 1));
	else
		rtn = malloc(sizeof(char) * (ft_strlen(input->line) - input->dollar_size));
	while (input->line[i])
	{
		if (input->line[i] == '"')
			add_env_double_quote(input, rtn, &i, &j);
		else if (input->line[i] == '\'')
		{
			append_str(rtn, input->line, &i, &j);
			while (input->line[i] != '\'' && input->line[i] != '\0')
				append_str(rtn, input->line, &i, &j);
			if (input->line[i] == '\'')
				append_str(rtn, input->line, &i, &j);
		}
		else
		{
			if (input->line[i] == '$')
				i += add_env(input, rtn, &i, &j);
			else
				append_str(rtn, input->line, &i, &j);
		}
	}
	rtn[j] = '\0';
	free(input->line);
	input->line = rtn;
	return ;
}
