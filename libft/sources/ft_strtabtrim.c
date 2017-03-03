/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:47:23 by bbetz             #+#    #+#             */
/*   Updated: 2017/03/02 12:47:44 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabtrim(char **input)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_get_size_tab((void **)input) + 1));
	while (input[i])
	{
		tab[i] = ft_strtrim(input[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
