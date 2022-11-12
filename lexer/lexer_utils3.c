/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:04:56 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 06:07:44 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

void	if_question_mark2(t_input *input)
{
	char	*tmp;

	tmp = ft_itoa(g_global.status);
	input->env_size += ft_strlen(tmp);
	free(tmp);
}
