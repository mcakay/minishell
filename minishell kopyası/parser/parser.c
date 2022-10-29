/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:30:40 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/28 23:44:58 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	init_prompt(t_prompt *prompt, char **envp, char **strs)
{
	t_command *cmds;

	cmds = NULL;
	prompt->envp = envp;
	if (get_cmds(&cmds, strs))
		return (1);
	init_redirections(&cmds, strs);
	get_path(prompt);
	prompt->cmds = cmds;
	return (0);
}

t_prompt	*parser(char **strs, char **envp)
{
	FILE *fp;

	fp = fopen("./logs/parser_log.txt", "w+");
	t_prompt	*prompt;

	prompt = malloc(sizeof(t_prompt));
	if (init_prompt(prompt, envp, strs))
		return (NULL);
	t_command *cmds = prompt->cmds;
	t_infile *infile = cmds->infile_list;
	t_outfile *outfile = cmds->outfile_list;
	t_here_doc *here_doc = cmds->here_doc_list;
	t_append *append = cmds->append_list;
	while (cmds)
	{
		fprintf(fp, "-------------------------\n");
		fprintf(fp, "cmd: %s\n", cmds->full_cmd[0]);
		while (infile)
		{
			fprintf(fp, "infile: %s\n", infile->infile);
			infile = infile->next;
		}
		while (outfile)
		{
			fprintf(fp, "outfile: %s\n", outfile->outfile);
			outfile = outfile->next;
		}
		while (here_doc)
		{
			fprintf(fp, "here_doc: %s\n", here_doc->here_doc);
			here_doc = here_doc->next;
		}
		while (append)
		{
			fprintf(fp, "append: %s\n", append->append);
			append = append->next;
		}
		cmds = cmds->next;
		if (cmds)
		{
			infile = cmds->infile_list;
			outfile = cmds->outfile_list;
			here_doc = cmds->here_doc_list;
			append = cmds->append_list;
		}
		fprintf(fp, "-------------------------\n");
	}
	fclose(fp);
	return (prompt);
}