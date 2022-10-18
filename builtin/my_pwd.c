/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:11 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/18 15:28:50 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

void	my_pwd(void)
{
	char	*path;

	path = getwd(NULL);
	ft_putendl_fd(path, 1);
	free (path);
}

void	my_echo(t_mini *a)
{
	int	i;

	if (a->full_cmd[1])
	{
		ft_printf("%d", a->full_cmd[1]);
		i = 2;
		while (a->full_cmd[i])
		{
			ft_printf(" %d", a->full_cmd[i]);
			i++;
		}
	}
	ft_printf("\n");
}

int	main(void)
{
	my_pwd();
	return (0);
}
