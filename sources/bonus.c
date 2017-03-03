/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:54:41 by bbetz             #+#    #+#             */
/*   Updated: 2017/03/02 15:54:45 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_room_list(t_env env)
{
	t_room *tmp;
	t_link *tmp2;

	tmp = env.start;
	while (tmp)
	{
		ft_putstr("Room ");
		ft_putcolorendl(tmp->name, LIGHT_BLUE);
		tmp2 = tmp->connection;
		while (tmp2)
		{
			ft_putstr(" - link with ");
			ft_putcolorendl(tmp2->room->name, LIGHT_RED);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	print_path(t_env env)
{
	t_room	*tmp;
	int		i;

	i = 0;
	ft_putstr("\n---------\n");
	while (env.paths && env.paths[i])
	{
		ft_putstr("path ");
		ft_putnbrendl(i);
		ft_putstr("- ");
		tmp = env.paths[i];
		while (tmp->next)
		{
			ft_putstr(tmp->name);
			ft_putstr("->");
			tmp = tmp->next;
		}
		ft_putendl(tmp->name);
		i++;
	}
	ft_putstr("---------\n\n");
}
