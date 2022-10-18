/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_envs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:44:16 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/18 03:26:11 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	init_envs(t_input *input, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	input->envs = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		input->envs[i] = ft_strdup(envp[i]);
		i++;
	}
	input->envs[i] = NULL;
}

void	init_dollar(t_input *input)
{
	(void)input;
	return ;
}
