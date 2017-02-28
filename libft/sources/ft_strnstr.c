/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:25:12 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/24 20:25:15 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;
	int k;
	int s;

	if (!*to_find)
		return (char *)(str);
	i = 0;
	while (str[i] && len > 0)
	{
		if (len < ft_strlen(to_find))
			return (NULL);
		k = 0;
		s = i;
		while (str[s] == to_find[k] && to_find[k] && str[s])
		{
			k++;
			s++;
		}
		if (to_find[k] == '\0')
			return ((char *)str + i);
		len--;
		i++;
	}
	return (NULL);
}
