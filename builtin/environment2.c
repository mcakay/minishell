/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:16:42 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/20 17:43:34 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

int	check_equal(char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] == '=')
			return (1);
	}
	return (0);
}

int	check_valid(char *a)
{
	int	i;

	if (!check_equal(a))
		return (0);
	i = 0;
	while (*a != '=')
		a++;
	a--;
	if (*a == ' ')
	{
		printf("export: `%s': not a valid identifier", ++a);
		return (0);
	}
	return (1);
}

int	my_export(t_prompt *p, t_mini *a)
{
	int	i;

	i = 1;
	if (!a->full_cmd[i])
		return (0);
	while (a->full_cmd[i])
	{
		if (!check_valid(a->full_cmd[i]))
			return (0);
		else if (is_present(p->env, a->full_cmd[i]))
		{
			delete_env(p->env, a->full_cmd[i]);
			add_env(p->env, a->full_cmd[i]);
		}
		else
			add_env(p->env, a->full_cmd[i]);
		i++;
	}
	return (1);
}

char	**add_env(t_prompt *p, char *a)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	while (p->env[i])
		i++;
	temp = ft_calloc(i + 1, sizeof(char *));
	if (!temp)
		return (0);
	i = 0;
	while (p->env[i])
	{
		temp[i] = p->env[i];
		i++;
	}
	temp[i] = ft_calloc(ft_strlen(a) + 1, sizeof(char));
	if (!temp[i])
		return (0);
	temp[i] = a;
	p->env[i] = temp[i];
	free (temp);
	return (1);
}
