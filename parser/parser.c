/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/23 05:57:05 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_prompt(t_prompt *prompt, char **envp, char **strs)
{
	t_command *cmds;

	cmds = NULL;
	copy_envp(envp, prompt);
	get_cmds(prompt, &cmds, strs);
	get_path(prompt);
	prompt->cmds = cmds;
}

t_prompt	parser(char **strs, char **envp)
{
	t_prompt	prompt;

	init_prompt(&prompt, envp, strs);
	for (t_infile *infile = prompt.infile_list; infile; infile = infile->next)
		printf("infile: %s\n", infile->infile);
	for (t_outfile *outfile = prompt.outfile_list; outfile; outfile = outfile->next)
		printf("outfile: %s\n", outfile->outfile);
	return (prompt);
}