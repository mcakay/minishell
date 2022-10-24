/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:39 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/24 16:04:55 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdlib.h>
# include "../minishell.h"

typedef struct s_prompt
{
	char	**envp;
}		t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}		t_mini;

void	my_pwd(void);
void	my_echo(t_mini *a);
int		my_cd(t_prompt *p, t_mini *a);
void	my_env(t_prompt *p);
char	*find_key_word(char *a);
int		is_present(char **p, char *a);
int		my_unset(t_prompt *p, t_mini *a);
int		del_env(t_prompt *p, char *a);
int		check_equal(char *a);
int		check_valid(char *a);
int		my_export(t_prompt *p, t_mini *a);
int		add_env(t_prompt *p, char *a);

#endif