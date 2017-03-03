/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:43:23 by bbetz             #+#    #+#             */
/*   Updated: 2017/03/02 16:43:24 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			count_max_path(t_env *env)
{
	int		nb;
	t_link	*tmp;

	nb = 0;
	tmp = env->start->connection;
	while (tmp)
	{
		if (tmp->room->dist_point == 0)
			return (-1);
		if (tmp->room->dist_point != -2)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}

t_room		*create_maillon_room(char *name, int start, int end, int coord[2])
{
	t_room *room;

	room = malloc(sizeof(t_room));
	room->name = ft_strdup(name);
	room->start = start;
	room->end = end;
	room->coord[0] = coord[0];
	room->coord[1] = coord[1];
	room->connection = NULL;
	room->next = NULL;
	room->ant_name = -1;
	room->nb_ants = 0;
	if (room->start)
		room->dist_point = -1;
	else if (room->end)
		room->dist_point = 0;
	else
		room->dist_point = -2;
	return (room);
}

int			get_smallest_dist(t_room *room)
{
	int		nb;
	t_link	*tmp;

	if (!room)
		return (-8);
	tmp = room->connection;
	if (!tmp)
		return (-8);
	nb = -8;
	while (tmp)
	{
		if (tmp->room->dist_point >= 0 && (nb == -8 ||
			(tmp->room->dist_point < nb)))
			nb = tmp->room->dist_point;
		tmp = tmp->next;
	}
	return (nb);
}

static void	get_all_smaller_path2(int i[2], t_env *env, t_room **room)
{
	t_link	*tmp_link2;

	while (i[1] != 0 && i[1] != -8)
	{
		if ((i[1] = get_smallest_dist(*room)) == -8)
			break ;
		add_room_to_paths(i[0], (*room), &(env->paths));
		i[1] = get_smallest_dist(*room);
		tmp_link2 = (*room)->connection;
		while (tmp_link2->room->dist_point &&
			tmp_link2->room->dist_point != i[1])
			tmp_link2 = tmp_link2->next;
		(*room) = tmp_link2->room;
	}
}

void		get_all_smaller_path(t_room *start, t_env *env)
{
	int		i[2];
	t_link	*tmp_link;
	t_room	*room;

	i[0] = 0;
	tmp_link = start->connection;
	i[1] = get_smallest_dist(start);
	while (i[1] != -2 && i[1] != -5 && i[1] != -8)
	{
		room = start;
		if ((i[1] = get_smallest_dist(room)) == -8)
			break ;
		add_room_to_paths(i[0], room, &(env->paths));
		tmp_link = start->connection;
		while (tmp_link->room->dist_point != i[1])
			tmp_link = tmp_link->next;
		room = tmp_link->room;
		get_all_smaller_path2(i, env, &room);
		if (i[1] == -8)
			clear_path(&(env->paths), i[0]);
		if (i[1] != -8)
			add_room_to_paths(i[0], room, &(env->paths));
		if (i[1] != -8)
			i[0]++;
	}
}
