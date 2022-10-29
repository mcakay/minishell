/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:49:17 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/21 01:53:17 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_path(t_prompt *prompt)
{
	int i;

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