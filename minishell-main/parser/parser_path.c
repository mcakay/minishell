/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:49:17 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 15:00:06 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_path(t_prompt *prompt)
{
	int	i;

	i = 0;
	while (prompt->envp[i])
	{
		if (ft_strncmp(prompt->envp[i], "PATH=", 5) == 0)
		{
			prompt->path = ft_split(prompt->envp[i] + 5, ':');
			break ;
		}
		i++;
	}
}
