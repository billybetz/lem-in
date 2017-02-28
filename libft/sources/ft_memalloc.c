/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 20:18:21 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/22 23:53:04 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*c;
	int				i;

	i = -1;
	c = NULL;
	c = (unsigned char *)malloc(size);
	if (c)
		while (size--)
			c[++i] = 0;
	return ((void *)c);
}
