/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:24:31 by bbetz             #+#    #+#             */
/*   Updated: 2016/12/02 18:25:18 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_get_distance(t_point pos_char, t_point p1)
{
	double res;

	res = sqrt(pow(pos_char.x - p1.x, 2) + pow(pos_char.y - p1.y, 2));
	return (res);
}
