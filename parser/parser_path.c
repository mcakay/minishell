/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:49:17 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/02 02:22:03 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_path(t_prompt *prompt)
{
	int i;

	i = 0;
	while (g_global.envp[i])
	{
		if (ft_strncmp(g_global.envp[i], "PATH=", 5) == 0)
		{
			prompt->path = ft_split(g_global.envp[i] + 5, ':');
			break ;
		}
		i++;
	}
}