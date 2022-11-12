/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:16:42 by bkayan            #+#    #+#             */
/*   Updated: 2022/11/12 05:21:21 by mcakay           ###   ########.fr       */
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

char	*find_max(void)
{
	int		i;
	int		j;
	char	*max;

	i = 0;
	max = g_global.envp[i];
	while (g_global.envp[i])
	{
		j = i;
		while (g_global.envp[j])
		{
			if (ft_strncmp(max, g_global.envp[j], ft_strlen(max)) < 0)
				max = g_global.envp[j];
			j++;
		}
		i++;
	}
	return (max);
}

char	*find_first(const char *a)
{
	char	*first;
	int		i;
	int		j;

	i = 0;
	first = find_max();
	while (g_global.envp[i])
	{
		j = i;
		while (g_global.envp[j])
		{
			if (!a && ft_strncmp(first, g_global.envp[j], ft_strlen(first)) > 0)
				first = g_global.envp[j];
			else if (ft_strncmp(first, g_global.envp[j], ft_strlen(first)) > 0
				&& a && ft_strncmp(a, g_global.envp[j], ft_strlen(a)) < 0)
				first = g_global.envp[j];
			j++;
		}
		i++;
	}
	return (first);
}

void	print_export(void)
{
	int		i;
	int		j;
	char	*a;

	a = find_first(0);
	i = 0;
	while (g_global.envp[i] && check_equal(g_global.envp[i]))
	{
		j = 0;
		printf("declare -x ");
		while (a[j] != '=')
			printf("%c", a[j++]);
		printf("%c\"", a[j++]);
		printf("%s\"\n", &a[j]);
		a = find_first(a);
		i++;
	}
	i = 0;
	while (g_global.envp[i])
	{
		if (!check_equal(g_global.envp[i]))
			printf("declare -x %s\n", g_global.envp[i]);
		i++;
	}
}
