/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:59:21 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/01 16:02:51 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(const char **tab)
{
	char	**tab2;
	int		i;

	i = 0;
	tab2 = malloc(sizeof(char *) * (ft_get_size_tab((void **)tab) + 1));
	while (tab[i])
	{
		tab2[i] = ft_strdup(tab[i]);
		i++;
	}
	tab2[i] = NULL;
	return (tab2);
}
