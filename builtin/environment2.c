/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:16:42 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/25 15:27:39 by bkayan           ###   ########.fr       */
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

	i = 0;
	b = ft_strdup(a);
	while (b[i] != '=' && b[i])
		i++;
	i--;
	if (i == -1 && b[i] == ' ')
	{
		printf("export: `%s': not a valid identifier", &b[i + 1]);
		free (b);
		return (0);
	}
	free (b);
	return (1);
}

//kullanabiliriz
char	*print_in_order(t_prompt *p, const char *a)
{
}

//alfabeitk olsun
void	print_export(t_prompt *p)
{
	int	i;
	int	j;

	while (check_equal(p->envp[i]) && p->envp[i])
	{
		printf("declare -x ");
		while (p->envp[i][j] != '=')
			printf("%c", p->envp[i][j++]);
		printf("%c\"", p->envp[i][j++]);
		printf("%s\"", &p->envp[i][j]);
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
		else
			add_env(p, a->full_cmd[i++]);
	}
	return (1);
}
