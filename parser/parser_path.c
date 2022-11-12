/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:49:17 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 04:31:53 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_path(t_prompt *prompt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_global.envp[i])
	{
		if (ft_strncmp(g_global.envp[i], "PATH=", 5) == 0)
		{
			prompt->path = ft_split(g_global.envp[i] + 5, ':');
			return ;
		}
		i++;
	}
	prompt->path = NULL;
}
