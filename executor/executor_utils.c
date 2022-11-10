/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:31:04 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/01 23:03:56 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	get_buffer(char **buffer, char *line)
{
	char *tmp;
	char *tmp2;
	tmp = ft_strjoin(*buffer, line);
	tmp2 = ft_strjoin(tmp, "\n");
	free(tmp);
	free(*buffer);
	*buffer = ft_strdup(tmp2);
	free(tmp2);
}