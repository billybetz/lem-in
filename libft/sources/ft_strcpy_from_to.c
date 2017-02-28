/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_from_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:09:07 by bbetz             #+#    #+#             */
/*   Updated: 2017/01/07 17:09:07 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_f_t(char *dest, const char *src, size_t from, size_t to)
{
	int i;

	i = 0;
	if (from > to)
		return (NULL);
	if (to > (ft_strlen(src) - 1))
		to = ft_strlen(src) - 1;
	while (src[from] && from <= to)
	{
		dest[i] = src[from];
		i++;
		from++;
	}
	dest[i] = '\0';
	return (dest);
}
