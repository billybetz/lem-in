/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:54:07 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/27 20:54:08 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_get_stdin(char ***map)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		*map = ft_strtabadd(*map, line);
		ft_strdel(&line);
	}
}
