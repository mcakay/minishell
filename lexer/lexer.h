/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:00:30 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/15 17:35:44 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

typedef struct s_input {
	int 	double_quotes;
	int 	single_quotes;
	char	**quotes;
	char	*line;
} 				t_input;

//quote_handler
void	quote_split(t_input *input);

//quote_counter
int		count_double_marks(char *line);
int 	count_single_marks(char *line);

//white_spaces
char	*remove_whitespaces(char *str);

//utils
int		is_special_char(char *str);
char	*add_marks(char *str);

#endif