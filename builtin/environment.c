/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:59:58 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/19 03:37:22 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

void	my_env(char **e)
{
	int	i;

	i = 0;
	while (e[i])
		printf("%s\n", e[i]);
}

//takes before =
char	*find_key_word(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '=')
		i++;
	a[i] = '\0';
	return (a);
}

//keyword listede var mı
int	is_present(char **p, char *a)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (find_key_word(p[i]) == find_key_word(a))
			return (ft_strlen(find_key_word(p[i])));
		i++;
	}
	return (0);
}

int	my_unset(t_prompt *p, t_mini *a)
{
	int		i;
	char	**temp;

	i = 1;
	while (a->full_cmd[i])
	{
		if (is_present(p->env, a->full_cmd[i]))
		{
			temp = del_env(p->env, a->full_cmd[i]);
			if (!temp)
				return (-1);
			p->env = temp;
			free (temp);
		}
		if (is_present(p->env_ex, a->full_cmd[i]))
		{
			temp = del_env(p->env_ex, a->full_cmd[i]);
			if (!temp)
				return (-1);
			p->env_ex = temp;
			free (temp);
		}
		i++;
	}
	return (0);
}

char	**del_env(char **p, char *a)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	while (p[i])
		i++;
	temp = ft_calloc(i - 1, sizeof(char *));
	if (!temp)
		return (0);
	i = 0;
	j = 0;
	while (p[i])
	{
		if (find_key_word(p[i]) != a)
			temp[j++] = p[i];
		i++;
	}
	return (temp);
}
