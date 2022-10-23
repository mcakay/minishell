/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:51:52 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/23 05:58:52 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_command	*create_node(char **strs, int i, int flag)
{
	t_command *node;
	int		j;

	j = 0;
	node = malloc(sizeof(t_command));
	node->full_cmd = malloc(sizeof(char *) * (i - flag + 1));
	while (j < i - flag)
	{
		node->full_cmd[j] = ft_strdup(strs[j + flag]);
		j++;
	}
	node->full_cmd[j] = NULL;
	node->infile = 0;
	node->outfile = 1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_command **root, char **strs, int i, int flag)
{
	t_command *curr;

	if (*root == NULL)
	{
		*root = create_node(strs, i, flag);
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = create_node(strs, i, flag);
	curr->next->prev = curr;
}


void	get_cmds(t_prompt *prompt, t_command **cmds, char **strs)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	while (strs[i])
	{
		if (strs[i][0] == '|')
		{
			add_node(cmds, strs, i, flag);
			flag = i + 1;
			i++;
		}
		else if (is_redirection(strs[i]) == 1 && strs[i + 1])
		{
			add_node_outfile(&prompt->outfile_list, strs[i + 1]);
			i += 2;
		}
		else if (is_redirection(strs[i]) == 2 && strs[i + 1])
		{
			add_node_infile(&prompt->infile_list, strs[i + 1]);
			i += 2;
		}
		else
			i++;
	}
	add_node(cmds, strs, i, flag);
}