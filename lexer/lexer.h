/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:00:30 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/17 03:40:10 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

typedef struct s_input {
	int 	double_quotes;
	int 	single_quotes;
	char	**args;
	char	*line;
} 				t_input;

//quote_handler
void	quote_split(t_input *input);

//quote_counter
int		count_double_quotes(char *line);
int 	count_single_quotes(char *line);

//utils
int		is_special_char(char c);
int		is_space_or_null(char c);
int		is_space(char c);

//remove_quotes
char	*remove_quotes(char *str);

#endif