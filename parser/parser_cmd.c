/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:51:52 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/18 15:45:43 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_mini	*create_node(char **strs, int i, int flag)
{
	t_mini *node;
	int		j;

	j = 0;
	node = malloc(sizeof(t_mini));
	node->full_cmd = malloc(sizeof(char *) * (i - flag + 1));
	while (j < i - flag)
	{
		node->full_cmd[j] = ft_strdup(strs[j + flag]);
		j++;
	}
	node->full_cmd[j] = NULL;
	node->next = NULL;
	return (node);
}

void	add_node(t_mini **root, char **strs, int i, int flag)
{
	t_mini *curr;

	if (*root == NULL)
	{
		*root = create_node(strs, i, flag);
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = create_node(strs, i, flag);
}


void	get_cmds(t_mini **cmds, char **strs)
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
			flag = i+1;
			i++;
		}
		else
			i++;
	}
	add_node(cmds, strs, i, flag);
	t_mini *curr = *cmds;
	int j = 0;
	while (curr)
	{
		for (int a = 0; curr->full_cmd[a]; a++)
			printf("cmd[%d]:command[%d]:%s\n",j, a, curr->full_cmd[a]);
		curr = curr->next;
		j++;
	}
}