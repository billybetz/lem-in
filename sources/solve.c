/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:37:46 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/27 01:37:47 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_path(t_env env)
{
	t_room	*tmp;
	int		i;

	i = 0;
	printf("\n---------\n");
	while (env.paths && env.paths[i])
	{
		printf("path %d\n-  ", i);
		tmp = env.paths[i];
		while (tmp->next)
		{
			printf("%s->", tmp->name);
			tmp = tmp->next;
		}
		printf("%s\n", tmp->name);
		i++;
	}
	printf("---------\n\n");
}

void	add_room_to_paths(int i, t_room *r, t_room ***paths)
{
	t_room *tmp;

	if (!(*paths)[i])
	{
		(*paths)[i] = create_maillon_room(r->name, r->start, r->end, r->coord);
	}
	else
	{
		tmp = (*paths)[i];
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = create_maillon_room(r->name, r->start, r->end, r->coord);
	}
	if (!(r->start) && !(r->end))
		r->dist_point = -5;
}

int		get_smallest_dist(t_room *room)
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
		if (tmp->room->dist_point >= 0 && (nb == -8 || (tmp->room->dist_point < nb)))
			nb = tmp->room->dist_point;
		tmp = tmp->next;
	}
	return (nb);
}

void	clear_path(t_room ***paths, int i)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = (*paths)[i];
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
		tmp = NULL;
		tmp = tmp2;
	}
	(*paths)[i] = NULL;
}

void	get_all_smaller_path(t_room *start, t_env *env)
{
	int		dist;
	int		i;
	t_link	*tmp_link;
	t_link	*tmp_link2;
	t_room	*room;

	i = 0;
	tmp_link = start->connection;
	dist = get_smallest_dist(start);
	while (dist != -2 && dist != -5 && dist != -8)
	{
		room = start;
		if ((dist = get_smallest_dist(room)) == -8)
			break ;
		add_room_to_paths(i, room, &(env->paths));
		tmp_link = start->connection;
		while (tmp_link->room->dist_point != dist)
			tmp_link = tmp_link->next;
		room = tmp_link->room;
		while (dist != 0 && dist != -8)
		{
			if ((dist = get_smallest_dist(room)) == -8)
				break ;
			add_room_to_paths(i, room, &(env->paths));
			dist = get_smallest_dist(room);
			tmp_link2 = room->connection;
			while (tmp_link2->room->dist_point && tmp_link2->room->dist_point != dist)
				tmp_link2 = tmp_link2->next;
			room = tmp_link2->room;
		}
		if (dist == -8)
			clear_path(&(env->paths), i);
		if (dist != -8)
			add_room_to_paths(i, room, &(env->paths));
		if (dist != -8)
			i++;
	}
}

int		count_max_path(t_env *env)
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

void	create_unique_path(t_env *env)
{
	t_room *r;

	r = env->start;
	env->paths = malloc(sizeof(t_room *) * 2);
	(env->paths)[0] = create_maillon_room(r->name, r->start, r->end, r->coord);
	while (r->end != 1)
		r = r->next;
	((env->paths)[0])->next = create_maillon_room(r->name, r->start, r->end, r->coord);
	((env->paths)[1]) = NULL;
	env->unique_path = 1;
}

int		find_valid_paths(t_env *env)
{
	int		dist;
	int		i;
	int		count;
	t_room	*tmp;
	t_link	*tmp2;

	dist = -2;
	i = -1;
	if ((count = count_max_path(env)) == -1)
	{
		create_unique_path(env);
		return (1);
	}
	env->paths = malloc(sizeof(t_room *) * (count + 1));
	while (++i < count + 1)
		(env->paths)[i] = NULL;
	tmp = env->start;
	while (tmp && !tmp->start)
		tmp = tmp->next;
	tmp2 = tmp->connection;
	if (!tmp)
		return (0);
	while (tmp2)
	{
		if (tmp2->room->dist_point > dist)
			dist = tmp2->room->dist_point;
		tmp2 = tmp2->next;
	}
	if (dist < 0)
		return (0);
	get_all_smaller_path(tmp, env);
	return (1);
}

void	recursive_dist_points(t_room *tmp, int dist)
{
	t_link *link;

	link = tmp->connection;
	while (link)
	{
		if (link->room->dist_point == -2 || link->room->dist_point > dist)
		{
			link->room->dist_point = dist;
			recursive_dist_points(link->room, dist + 1);
		}
		link = link->next;
	}
}

int		apply_dist_points(t_env env)
{
	int		dist;
	t_room	*tmp;

	dist = 1;
	tmp = env.start;
	while (tmp && !tmp->end)
		tmp = tmp->next;
	if (!tmp)
		return (0);
	recursive_dist_points(tmp, dist);
	return (1);
}
