/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:51:52 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/26 16:18:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_command	*create_node(char **strs, int i, int flag)
{
	t_command *node;
	int		j;
	int		k;

	j = 0;
	k = 0;
	node = malloc(sizeof(t_command));
	node->full_cmd = malloc(sizeof(char *) * (i - flag + 1));
	while (j < i - flag)
	{
		if (is_redirection(strs[j + flag]))
			j += 2;
		else
		{
			node->full_cmd[k] = ft_strdup(strs[j + flag]);
			j++;
			k++;
		}
	}
	node->full_cmd[k] = NULL;
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


int	get_cmds(t_command **cmds, char **strs)
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
		if (is_redirection(strs[i]) == 1)
		{
			if (strs[i + 1] == NULL)
				return(printf("minishell: syntax error near unexpected token `newline'\n"));
			i += 2;
		}
		else
			i++;
	}
	add_node(cmds, strs, i, flag);
	return (0);
}