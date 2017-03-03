/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolorendl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:46:02 by bbetz             #+#    #+#             */
/*   Updated: 2017/03/02 17:46:04 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putcolorendl(char *s, char *color)
{
	ft_putchar('\0');
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr(DEFAULT);
	ft_putchar('\n');
}
