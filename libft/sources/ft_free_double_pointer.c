/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:39:07 by bbetz             #+#    #+#             */
/*   Updated: 2016/12/04 13:41:44 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_free_double_pointer(void ***pointer)
{
	int i;

	i = 0;
	if (!*pointer)
		return ;
	while ((*pointer)[i])
	{
		free((*pointer)[i]);
		(*pointer)[i] = NULL;
		i++;
	}
	free(*pointer);
	*pointer = NULL;
}
