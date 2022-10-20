/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:39 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/20 18:00:55 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdlib.h>

void	my_pwd(void);
void	my_echo(t_mini *a);
int		my_cd(t_prompt *p, t_mini *a);
void	my_env(char **e);
char	*find_key_word(char *a);
int		is_present(char **p, char *a);
int		my_unset(t_prompt *p, t_mini *a);
int		del_env(t_prompt *p, char *a);

#endif