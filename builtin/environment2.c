/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:16:42 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/20 17:09:12 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

int	check_equal(char *a)
{
	int	i;

	i = 0;
	while ()
	{}
}

int	my_export(t_prompt *p, t_mini *a)
{
	int	i;

	i = 1;
	if (check_valid)
		return (0);
	while (a->full_cmd[i])
	{
		if (check_valid)
			return (0);
		else if (is_present(p->env, a->full_cmd[i]))
		{
			delete_env;
			add_env;
		}
		else ()
			add_env;
		i++;
	}
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
