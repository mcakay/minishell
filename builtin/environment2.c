/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:16:42 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/19 03:41:00 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

int	check_equal(char *a)
{
	int	i;

	i = 0;
	while ()
}

void	my_export(t_prompt *p, t_mini *a)
{
	int	i;

	i = 1;
	while (a->full_cmd[i])
	{
		if (is_present(p->env, a->full_cmd[i]))
		{
			change_env
		}
		else if (check_equal(a->full_cmd[i]))
		{
			add_env_ex
		}
		else
			add_env
		i++;
	}
}

//fix
char	**change_env(t_prompt *p, char **p, char *a)
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

char	**add_env(t_prompt *p, char **p, char *a)
{}