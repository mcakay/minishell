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

int	init_input(t_input *input, char *line, char **envp, FILE *fp)//
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
	calc_size(input, envp);
	reset_iters(input);
	calc_args_size(input);
	fprintf(fp, "args_size: %d\ndollar_size: %d\nenv_size: %d\n", input->args_size, input->dollar_size, input->env_size);
	reset_iters(input);
	fprintf(fp, "before env: %s\n", input->line);
	lexer_add_env(input, envp);
	fprintf(fp, "after env: %s\n", input->line);
	reset_iters(input);
	quote_split(input);
	free(input->line);
	return (0);
}

char	**lexer(char *line, char **envp)
{
	FILE *fp;//

	fp = fopen("./logs/lexer_log.txt", "w+");//
	t_input input;
	int		i;

	if (init_input(&input, line, envp, fp))
		return (NULL);
	i = 0;
	while (input.args[i])
	{
		reset_iters(&input);
		input.args[i] = remove_quotes(input.args[i], &input);
		i++;
	}
	for (int i = 0; input.args[i]; i++)
		fprintf(fp, "args[%d] = |%s|\n", i, input.args[i]);//
	fclose(fp);//
	return (input.args);
}