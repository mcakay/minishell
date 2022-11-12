/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:29:35 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 04:29:22 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

char	**copy_env(char **envp)
{
	char	**rtn;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	rtn = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		rtn[i] = ft_strdup(envp[i]);
		i++;
	}
	rtn[i] = NULL;
	return (rtn);
}
