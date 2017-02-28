/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdirectory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:50:31 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/03 14:50:32 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isdirectory(char *path)
{
	DIR *ret;

	if ((ret = opendir(path)) == NULL)
		return (0);
	else
	{
		closedir(ret);
		return (1);
	}
}
