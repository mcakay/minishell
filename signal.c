/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:52:14 by mcakay            #+#    #+#             */
/*   Updated: 2022/11/10 23:40:37 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d(void)
{
	printf("exit\n");
	exit(0);
}

void	sigint_handler(int sig)
{
	int	status;

	(void)sig;
	waitpid(-1, &status, 0);
	if (WTERMSIG(status) == SIGINT)
	{
		printf("\n");
		return ;
	}
	g_global.check = 1;
	ioctl(0, TIOCSTI, "\n");
    write(1, "\033[A", 3);
}

void	sigquit_handler_in_process(int sig)
{
	int	status;

	(void)sig;
	waitpid(-1, &status, 0);
	
	if (WTERMSIG(status) == SIGQUIT)
	{
		printf("Quit: %d\n", sig);
		return ;
	}
}
