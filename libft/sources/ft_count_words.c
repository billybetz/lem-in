/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 18:43:22 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/17 18:47:43 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *str)
{
	int nb_word;
	int i;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 1)
			i++;
		else
		{
			while ((ft_isspace(str[i]) == 0) && str[i] != '\0')
				i++;
			nb_word++;
		}
	}
	return (nb_word);
}
