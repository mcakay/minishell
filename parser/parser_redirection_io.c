/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirection_io.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:04:59 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/23 05:14:42 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_infile	*create_node_infile(char *str)
{
	t_infile	*new;

	new = malloc(sizeof(t_infile));
	new->infile = ft_strdup(str);
	new->next = NULL;
	return (new);

}

t_outfile	*create_node_outfile(char *str)
{
	t_outfile	*new;

	new = malloc(sizeof(t_outfile));
	new->outfile = ft_strdup(str);
	new->next = NULL;
	return (new);
}

void	add_node_infile(t_infile **root, char *str)
{
	t_infile *curr;

	if (*root == NULL)
	{
		*root = create_node_infile(str);
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = create_node_infile(str);
}

void	add_node_outfile(t_outfile **root, char *str)
{
	t_outfile *curr;

	if (*root == NULL)
	{
		*root = create_node_outfile(str);
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = create_node_outfile(str);
}