/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 05:20:42 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 05:21:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	my_exit(int status)
{
	printf("exit\n");
	exit(status);
}

int	my_export(t_command *a)
{
	int		i;
	char	*key;

	i = 1;
	if (!a->full_cmd[i])
	{
		print_export();
		return (0);
	}
	while (a->full_cmd[i])
	{
		if (!check_valid(a->full_cmd[i]))
			return (0);
		else if (check_equal(a->full_cmd[i])
			&& is_present(g_global.envp, a->full_cmd[i]))
		{
			key = find_key_word(a->full_cmd[i]);
			del_env(key);
			add_env(a->full_cmd[i++]);
			free (key);
		}
		else if (!is_present(g_global.envp, a->full_cmd[i]))
			add_env(a->full_cmd[i++]);
	}
	return (1);
}
