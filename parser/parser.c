/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/24 04:16:25 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	init_prompt(t_prompt *prompt, char **envp, char **strs)
{
	t_command *cmds;

	cmds = NULL;
	copy_envp(envp, prompt);
	if (get_cmds(&cmds, strs))
		return (1);
	init_redirections(&cmds, strs);
	get_path(prompt);
	prompt->cmds = cmds;
	return (0);
}

t_prompt	*parser(char **strs, char **envp)
{
	t_prompt	*prompt;

	prompt = malloc(sizeof(t_prompt));
	if (init_prompt(prompt, envp, strs))
		return (NULL);
	t_command *cmds = prompt->cmds;
	t_infile *infile = cmds->infile_list;
	t_outfile *outfile = cmds->outfile_list;
	while (cmds)
	{
		printf("-------------------------\n");
		printf("cmd: %s\n", cmds->full_cmd[0]);
		while (infile)
		{
			printf("infile: %s\n", infile->infile);
			infile = infile->next;
		}
		while (outfile)
		{
			printf("outfile: %s\n", outfile->outfile);
			outfile = outfile->next;
		}
		cmds = cmds->next;
		if (cmds)
		{
			infile = cmds->infile_list;
			outfile = cmds->outfile_list;
		}
		printf("-------------------------\n");
	}
	return (prompt);
}