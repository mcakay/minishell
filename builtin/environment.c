/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayan <bkayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:59:58 by bkayan            #+#    #+#             */
/*   Updated: 2022/10/18 21:41:38 by bkayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_env(t_prompt *p)
{
	int	i;

	i = 0;
	while (p->envp[i])
		printf("%s\n", p->envp[i]);
}

int	my_unset(t_prompt *p, t_mini *a)
{
	int		i;
	int		j;
	char	**temp;

	while (p->envp[i])
		i++;
	temp = ft_calloc(i - 1, sizeof(char *));
	if (!temp)
		return (-1);
	i = 0;
	j = 0;
	while (p->envp[i])
	{
		if (p->envp[i] != a->full_cmd[1])
			temp[j++] == p->envp[i];
		i++;
	}
	free (p->envp[i]);
	p->envp = temp;
	return (0);
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
