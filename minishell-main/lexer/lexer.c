/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:00:08 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 15:29:28 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	init_input(t_input *input, char *line, char **envp)
{
	input->double_quotes = count_double_quotes(line);
	input->single_quotes = count_single_quotes(line);
	input->args_size = 0;
	input->dollar_size = 0;
	input->env_size = 0;
	if (input->double_quotes % 2 != 0 || input->single_quotes % 2 != 0)
		return (printf("Syntax Error: quotes not closed\n"));
	input->line = ft_strdup(line);
	init_envs(input, envp);
	calc_size(input, 0, 0);
	calc_args_size(input);
	printf("args_size: %d\n", input->args_size);
	//init_dollar(input);
	quote_split(input);
	return (0);
}

char	**lexer(char *line, char **envp)
{
	t_input	input;
	int		i;

	if (init_input(&input, line, envp))
		exit(1);
	i = 0;
	while (input.args[i])
	{
		input.args[i] = remove_quotes(input.args[i]);
		i++;
	}
	for (int i = 0; input.args[i]; i++)
		printf("args[%d] = %s\n", i, input.args[i]);
	return (input.args);
}