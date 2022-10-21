/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:31:34 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/20 22:31:35 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	copy_envp(char **envp, t_prompt *prompt)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	prompt->envp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		prompt->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	prompt->envp[i] = NULL;
}