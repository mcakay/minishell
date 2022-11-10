/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:00:30 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/02 02:15:07 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct s_input {
	int 	double_quotes;
	int 	single_quotes;
	char	**args;
	char	**envs;
	char	*line;
	int		args_size;
	int		dollar_size;
	int		env_size;
	int		i;
	int		j;
	int		k;
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
void	append_str(char *s1, char *str, t_input *input);
void	skip_quotes(t_input *input, char quote);
void	reset_iters(t_input *input);

//remove_quotes
char	*remove_quotes(char *str, t_input *input);

//calc_size
void	calc_size(t_input *input);
void	calc_args_size(t_input *input);

//env
void	lexer_add_env(t_input *input);


#endif