/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:29:29 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/28 01:12:18 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

typedef struct s_infile
{
	char	*infile;
	struct s_infile *next;
}			t_infile;

typedef struct s_outfile
{
	char	*outfile;
	struct s_outfile *next;
}			t_outfile;

typedef struct s_here_doc
{
	char	*here_doc;
	struct s_here_doc *next;
}			t_here_doc;

typedef struct s_append
{
	char	*append;
	struct s_append *next;
}			t_append;
#endif