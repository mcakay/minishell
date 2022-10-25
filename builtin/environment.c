/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:59:58 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/25 20:24:14 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*find_key_word(char *a)
{
	int		i;
	char	*b;

	i = 0;
	b = ft_strdup(a);
	while (b[i] != '=' && b[i])
		i++;
	b[i] = '\0';
	return (b);
}

int	is_present(char **p, char *a)
{
	char	*p_key;
	char	*a_key;
	int		i;

	i = 0;
	a_key = find_key_word(a);
	while (p[i])
	{
		p_key = find_key_word(p[i]);
		if (!ft_strncmp(p_key, a_key, ft_strlen(p_key)))
			return (1);
		i++;
		free (p_key);
	}
	free (a_key);
	return (0);
}

int	my_unset(t_prompt *p, t_command *a)
{
	int		i;

	i = 1;
	while (a->full_cmd[i])
	{
		if (is_present(p->envp, a->full_cmd[i]))
		{
			if (!del_env(p, a->full_cmd[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	del_env(t_prompt *p, char *a)
{
	char	**temp;
	char	*keyword;
	int		i;
	int		j;

	i = 0;
	while (p->envp[i])
		i++;
	temp = ft_calloc(i, sizeof(char *));
	if (!temp)
		return (0);
	i = 0;
	j = 0;
	while (p->envp[i])
	{
		keyword = find_key_word(p->envp[i]);
		if (ft_strncmp(keyword, a, ft_strlen(keyword)))
			temp[j++] = p->envp[i];
		i++;
	}
	temp[j] = 0;
	free (p->envp);
	p->envp = temp;
	return (1);
}

int	add_env(t_prompt *p, char *a)
{
	char	**temp;
	int		i;

	i = 0;
	while (p->envp[i])
		i++;
	temp = ft_calloc(i + 2, sizeof(char *));
	if (!temp)
		return (0);
	i = 0;
	while (p->envp[i])
	{
		temp[i] = p->envp[i];
		i++;
	}
	temp[i] = ft_calloc(ft_strlen(a) + 1, sizeof(char));
	if (!temp[i])
		return (0);
	temp[i] = a;
	free (p->envp);
	p->envp = temp;
	return (1);
}