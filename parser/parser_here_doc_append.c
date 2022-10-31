/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_here_doc_append.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:13:17 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/28 16:43:15 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_here_doc	*create_node_here_doc(char *str)
{
	t_here_doc	*new;

	new = malloc(sizeof(t_here_doc));
	new->here_doc = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_append	*create_node_append(char *str)
{
	t_append	*new;

	new = malloc(sizeof(t_append));
	new->append = ft_strdup(str);
	new->next = NULL;
	return (new);
}

void	add_node_here_doc(t_here_doc **root, char *str)
{
	t_here_doc *curr;

	if (*root == NULL)
	{
		*root = create_node_here_doc(str);
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = create_node_here_doc(str);
}

void	add_node_append(t_append **root, char *str)
{
	t_append *curr;

	if (*root == NULL)
	{
		*root = create_node_append(str);
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = create_node_append(str);
}