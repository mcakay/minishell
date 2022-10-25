/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:16:42 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/25 16:55:00 by bkayan           ###   ########.fr       */
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
		i++;
	}
	return (0);
}

int	check_valid(char *a)
{
	int		i;
	char	*b;

	i = 0;
	b = ft_strdup(a);
	while (b[i] != '=' && b[i])
		i++;
	i--;
	if (i == -1 || b[i] == ' ')
	{
		printf("export: `%s': not a valid identifier\n", b);
		free (b);
		return (0);
	}
	free (b);
	return (1);
}

char	*find_first(t_prompt *p, const char *a)
{
	char	*first;
	int		i;
	int		j;

	i = 0;
	while (p->envp[i])
	{
		j = i + 1;
		while (p->envp[j] && (!a
				|| (ft_strncmp(a, p->envp[j], ft_strlen(a)) < 0)))
		{
			if (ft_strncmp(p->envp[i], p->envp[j], ft_strlen(p->envp[i])) > 0)
				first = p->envp[j];
			j++;
		}
		i++;
	}
	return (first);
}

void	print_export(t_prompt *p)
{
	int		i;
	int		j;
	char	*a;

	a = find_first(p, 0);
	i = 0;
	while (p->envp[i] && check_equal(p->envp[i]))
	{
		j = 0;
		printf("declare -x ");
		while (a[j] != '=')
			printf("%c", a[j++]);
		printf("%c\"", a[j++]);
		printf("%s\"\n", &a[j]);
		a = find_first(p, a);
		i++;
	}
	i = 0;
	while (!check_equal(p->envp[i]) && p->envp[i])
	{
		printf("declare -x %s", p->envp[i]);
		i++;
	}
}

int	my_export(t_prompt *p, t_mini *a)
{
	int		i;
	char	*key;

	i = 1;
	if (!a->full_cmd[i])
	{
		print_export(p);
		return (0);
	}
	while (a->full_cmd[i])
	{
		if (check_equal(a->full_cmd[i]) && !check_valid(a->full_cmd[i]))
			return (0);
		else if (check_equal(a->full_cmd[i])
			&& is_present(p->envp, a->full_cmd[i]))
		{
			key = find_key_word(a->full_cmd[i]);
			del_env(p, key);
			add_env(p, a->full_cmd[i++]);
			free (key);
		}
		else if (!is_present(p->envp, a->full_cmd[i]))
			add_env(p, a->full_cmd[i++]);
	}
	return (1);
}
