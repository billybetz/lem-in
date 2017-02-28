/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:20:14 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/24 19:21:26 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	if (str)
		return (ft_strcpy(str, src));
	else
		return (NULL);
}
