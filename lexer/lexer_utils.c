/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:29:55 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 05:48:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_special_char(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int	is_space_or_null(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	append_str(char *s1, char *str, t_input *input)
{
	s1[input->j] = str[input->i];
	input->i++;
	input->j++;
}

void	reset_iters(t_input *input)
{
	input->i = 0;
	input->j = 0;
	input->k = 0;
	input->l = 0;
	input->a = 0;
	input->b = 0;
}
