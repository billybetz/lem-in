/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:33:13 by bbetz             #+#    #+#             */
/*   Updated: 2017/03/02 17:33:14 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_room_to_paths(int i, t_room *r, t_room ***paths)
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
