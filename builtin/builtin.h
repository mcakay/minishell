/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:39 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/25 20:26:04 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdlib.h>
# include "../minishell.h"

void	my_pwd(void);
void	my_echo(t_command *a);
int		my_cd(t_prompt *p, t_command *a);
void	my_env(t_prompt *p);
char	*find_key_word(char *a);
int		is_present(char **p, char *a);
int		my_unset(t_prompt *p, t_command *a);
int		del_env(t_prompt *p, char *a);
int		check_equal(char *a);
int		check_valid(char *a);
int		my_export(t_prompt *p, t_command *a);
int		add_env(t_prompt *p, char *a);
void	print_export(t_prompt *p);
char	*find_first(t_prompt *p, const char *a);

#endif