/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:27:18 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/23 05:08:23 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_redirection(char *str)
{
	if (ft_strcmp(str, ">") == 0)
		return (1);
	else if (ft_strcmp(str, "<") == 0)
		return (2);
	else if (ft_strcmp(str, ">>") == 0)
		return (3);
	else if (ft_strcmp(str, "<<") == 0)
		return (4);
	else
		return (0);
}
