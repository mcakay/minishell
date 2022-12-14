/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 04:38:33 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/14 06:15:47 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	init_input(t_input *input, char *line)
{
	input->double_quotes = count_double_quotes(line);
	input->single_quotes = count_single_quotes(line);
	input->args_size = 0;
	input->dollar_size = 0;
	input->env_size = 0;
	reset_iters(input);
	if (input->double_quotes % 2 != 0 || input->single_quotes % 2 != 0)
		return (printf("Syntax Error: quotes not closed\n"));
	input->line = ft_strdup(line);
	calc_size(input);
	reset_iters(input);
	calc_args_size(input);
	reset_iters(input);
	lexer_add_env(input);
	reset_iters(input);
	quote_split(input);
	free(input->line);
	return (0);
}

char	**lexer(char *line)
{
	t_input	input;

	if (init_input(&input, line))
		return (NULL);
	return (input.args);
}
