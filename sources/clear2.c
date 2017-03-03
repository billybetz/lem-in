/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:34:49 by bbetz             #+#    #+#             */
/*   Updated: 2017/03/02 16:35:01 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_paths(t_room **p)
{
	t_room	*r;
	int		i;

	i = 0;
	while (p[i])
	{
		while (p[i])
		{
			r = p[i]->next;
			free(p[i]->name);
			free(p[i]);
			p[i] = r;
		}
		i++;
	}
	free(p);
}

void		free_start(t_room *r)
{
	t_room *tmp;
	t_link *co;
	t_link *co2;

	while (r)
	{
		tmp = r->next;
		co = r->connection;
		while (co)
		{
			co2 = co->next;
			free(co);
			co = co2;
		}
		free(r->name);
		free(r);
		r = tmp;
	}
}

void		clear_path(t_room ***paths, int i)
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
