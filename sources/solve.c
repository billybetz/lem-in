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

#include "lem_in.h"

static void	create_unique_path(t_env *env)
{
	t_room *r;

	r = env->start;
	env->paths = malloc(sizeof(t_room *) * 2);
	(env->paths)[0] = create_maillon_room(r->name, r->start, r->end, r->coord);
	while (r->end != 1)
		r = r->next;
	((env->paths)[0])->next =
	create_maillon_room(r->name, r->start, r->end, r->coord);
	((env->paths)[1]) = NULL;
	env->unique_path = 1;
}

static int	find_valid_paths2(int i[3], t_env *env, t_room **tmp)
{
	i[2] = -2;
	i[0] = -1;
	if ((i[1] = count_max_path(env)) == -1)
	{
		create_unique_path(env);
		return (1);
	}
	env->paths = malloc(sizeof(t_room *) * (i[1] + 1));
	while (++i[0] < i[1] + 1)
		(env->paths)[i[0]] = NULL;
	(*tmp) = env->start;
	while ((*tmp) && !(*tmp)->start)
		(*tmp) = (*tmp)->next;
	return (0);
}

int			find_valid_paths(t_env *env)
{
	int		i[3];
	t_room	*tmp;
	t_link	*tmp2;

	tmp = NULL;
	if (find_valid_paths2(i, env, &tmp) == 1)
		return (1);
	tmp2 = tmp->connection;
	if (!tmp)
		return (0);
	while (tmp2)
	{
		if (tmp2->room->dist_point > i[2])
			i[2] = tmp2->room->dist_point;
		tmp2 = tmp2->next;
	}
	if (i[2] < 0)
		return (0);
	get_all_smaller_path(tmp, env);
	return (1);
}

void		recursive_dist_points(t_room *tmp, int dist)
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

int			apply_dist_points(t_env env)
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
