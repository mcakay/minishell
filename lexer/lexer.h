/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:00:30 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/20 17:08:00 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

typedef struct s_input {
	int 	double_quotes;
	int 	single_quotes;
	char	**args;
	char	**envs;
	char	*line;
	int		args_size;
	int		dollar_size;
	int		env_size;
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
void	append_str(char *s1, char *s2, int *i, int *j);

//remove_quotes
char	*remove_quotes(char *str);

//env
void	init_dollar(t_input *input);
void	init_envs(t_input *input, char **envp);

//calc_size
void	calc_size(t_input *input);


#endif