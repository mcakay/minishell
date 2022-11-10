/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */ 
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:00:08 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 12:59:12 by mcakay           ###   ########.fr       */
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
	t_input input;
	int		i;

	if (init_input(&input, line))
		return (NULL);
	i = 0;
	while (input.args[i])
	{
		reset_iters(&input);
		input.args[i] = remove_quotes(input.args[i], &input);
		i++;
	}
	return (input.args);
}