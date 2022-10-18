/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:59:58 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/18 20:53:39 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_env(t_prompt *p)
{
	int	i;

	i = 0;
	while (p->envp[i])
		printf("%s\n", p->envp[i]);
}

void	my_export(t_prompt *p, int ac, t_mini *a)
{
	int	i;

	if (ac <= 1)
		my_env(p);
	else
	{
		i = 0;
		while (p->envp[i])
		{
			if (ft_strncmp(a->full_cmd[1], p->envp[i]) == 0,
				ft_strlen(p->envp[i]))
				p->envp[i] = 0;
			i++;
		}
	}
}

void	my_unset(t_prompt *p)
{
	
}