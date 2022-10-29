/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:52:14 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/28 20:54:58 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d(void)
{
	//write(1, "\033[Aexit\n", 9);
	printf("exit\n");
	exit(0);
}

void	sigint_handler(int sig)
{
	(void)sig;
	//g_global.status = 130;
	/*
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	*/
}
