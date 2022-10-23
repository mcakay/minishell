/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:29:29 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/23 05:10:16 by mcakay           ###   ########.fr       */
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

#endif