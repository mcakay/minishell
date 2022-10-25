/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:16:42 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/25 14:14:46 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
	int		i;
	char	*b;

	if (!check_equal(a))
		return (0);
	i = 0;
	b = ft_strdup(a);
	while (b[i] != '=' && b[i])
		i++;
	i--;
	if (b[i] == ' ')
	{
		printf("export: `%s': not a valid identifier", &b[i + 1]);
		free (b);
		return (0);
	}
	free (b);
	return (1);
}

int	my_export(t_prompt *p, t_mini *a)
{
	int		i;
	char	*key;

	i = 1;
	if (!a->full_cmd[i])
		return (0);
	while (a->full_cmd[i])
	{
		if (!check_valid(a->full_cmd[i]))
			return (0);
		else if (is_present(p->envp, a->full_cmd[i]))
		{
			key = find_key_word(a->full_cmd[i]);
			del_env(p, key);
			add_env(p, a->full_cmd[i]);
			free (key);
		}
		else
			add_env(p, a->full_cmd[i]);
		i++;
	}
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
