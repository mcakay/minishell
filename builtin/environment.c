/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:59:58 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/18 20:28:56 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_env(t_prompt *p)
{
	int	i;

	i = 0;
	while (p->envp[i])
		printf("%s\n", p->envp[i]);
}

void	my_export(t_prompt *p)
{
	
}

void	my_unset(t_prompt *p)
{
	
}