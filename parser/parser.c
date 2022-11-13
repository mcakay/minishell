/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/13 15:44:16 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

int	init_prompt(t_prompt *prompt, char **strs)
{
	t_command	*cmds;

	cmds = NULL;
	if (get_cmds(&cmds, strs))
		return (1);
	init_redirections(&cmds, strs);
	get_path(prompt);
	prompt->cmds = cmds;
	return (0);
}

t_prompt	*parser(char **strs)
{
	t_prompt	*prompt;
	t_command	*curr;
	t_input		*input;
	int			i;
	//int			j;

	input = malloc(sizeof(t_input));
	prompt = malloc(sizeof(t_prompt));
	if (init_prompt(prompt, strs))
		return (NULL);
	curr = prompt->cmds;
	//j = 0;
	while (curr)
	{
		i = 0;
		while (curr->full_cmd[i])
		{
			reset_iters(input);
			curr->full_cmd[i] = remove_quotes(curr->full_cmd[i], input);
			i++;
		}
		/*
		for (int i = 0; curr->full_cmd[i]; i++)
			printf("full_cmd[%d][%d]: %s\n", j, i, curr->full_cmd[i]);	
		for (t_infile *infile = curr->infile_list; infile; infile = infile->next)
			printf("infile_list: %s\n", infile->infile);
		for (t_outfile *outfile = curr->outfile_list; outfile; outfile = outfile->next)
			printf("outfile_list: %s\n", outfile->outfile);
		for (t_append *append = curr->append_list; append; append = append->next)
			printf("appendfile_list: %s\n", append->append);
		for (t_here_doc *heredoc = curr->here_doc_list; heredoc; heredoc = heredoc->next)
			printf("heredoc_list: %s\n", heredoc->here_doc);
		j++;
		*/
		curr = curr->next;
	}
	free(input);
	return (prompt);
}
