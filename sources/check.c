/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:02:20 by bbetz             #+#    #+#             */
/*   Updated: 2017/03/02 16:02:21 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_if_name_exist(char *name, t_env env)
{
	t_room	*tmp;

	tmp = env.start;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		check_name_validity(char *name)
{
	if (!name || !name[0])
		return (0);
	if (name[0] == 'L' || name[0] == '#')
		return (0);
	if (ft_strfindchar(name, '-') != -1)
		return (0);
	return (1);
}

int		check_if_connect_exist(char *name1, char *name2, t_env env)
{
	t_room	*tmp;
	t_link	*tmp2;

	tmp = env.start;
	while (tmp && ft_strcmp(tmp->name, name1))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	tmp2 = tmp->connection;
	while (tmp2 && ft_strcmp(tmp2->room->name, name2))
		tmp2 = tmp2->next;
	if (!tmp2)
		return (0);
	return (1);
}
