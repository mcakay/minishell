/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:00:30 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/14 13:35:52 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MARKS_H
#define MARKS_H

typedef struct s_input {
	int 	double_quotes;
	int 	single_quotes;
	char	**quotes_in;
	char	**quotes_out;
} 				t_input;

//utils
void	quote_in_split(t_input *input, char *line);
void	quote_out_split(t_input *input, char *line);

#endif