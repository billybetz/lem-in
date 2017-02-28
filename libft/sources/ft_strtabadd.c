/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:01:16 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/01 18:06:28 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
char		**ft_strtabadd(char **tab, char *str)
{
	char	**tab2;
	int		i;

	i = -1;
	if (!str)
		return (tab);
	if (!tab || !tab[0])
	{
		tab2 = malloc(sizeof(char *) * 2);
		tab2[0] = ft_strdup(str);
		tab2[1] = NULL;
		return (tab2); 
	}
	tab2 = malloc(sizeof(char *) * (ft_get_size_tab((void**)tab) + 2));
	while (tab[++i])
		tab2[i] = tab[i];
	tab2[i++] = ft_strdup(str);
	tab2[i] = NULL;
	return (tab2);
}
