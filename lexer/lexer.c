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
	free(line);
	init_envs(input, envp);
	calc_size(input);
	init_dollar(input);
	quote_split(input);
	return (0);
}

char	**lexer(char *line, char **envp)
{
	t_input input;
	int		i;

	if (*line == '\0')
		return (NULL);
	if (init_input(&input, line, envp))
		return (NULL);
	i = 0;
	while (input.args[i])
	{
		input.args[i] = remove_quotes(input.args[i]);
		i++;
	}
	for (int i = 0; input.args[i] != NULL; i++)
		printf("args[%d]=%s\n", i, input.args[i]);
	return (input.args);
}