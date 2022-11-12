/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:39 by bkayan            #+#    #+#             */
/*   Updated: 2022/11/12 04:56:24 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdlib.h>
# include "../minishell.h"

void	my_pwd(void);
void	my_echo(t_command *a);
int		my_cd(t_command *a);
void	my_env(void);
void	my_exit(int status);
char	*find_key_word(char *a);
int		is_present(char **p, char *a);
int		my_unset(t_command *a);
int		del_env(char *a);
int		check_equal(char *a);
int		check_valid(char *a);
int		my_export(t_command *a);
int		add_env(char *a);
void	print_export(void);
char	*find_first(const char *a);

#endif