/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:52:14 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/12 01:17:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_global.pid != 0)
	{
		write(1, "\033[A", 3);
		ioctl(0, TIOCSTI, "\n");
	}
	else
		printf("\n");
}

void	eof_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

void	sigquit_handler(int sig)
{
	(void)sig;
	if (g_global.pid == 0)
		printf("Quit: 3\n");
}