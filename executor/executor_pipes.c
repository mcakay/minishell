/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:26:51 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 05:48:50 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	init_pipes(t_prompt *prompt)
{
	t_command	*curr;
	int			i;

	i = 0;
	curr = prompt->cmds;
	while (curr->next)
	{
		pipe(curr->fd);
		curr = curr->next;
	}
}
