/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_spacearround.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:39:28 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/03 19:46:42 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_space(const char *str, char c, int len)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (len > 1)
	{
		while (str[i])
		{
			if (str[i] == c)
				count++;
			i++;
		}
		count *= 2;
		if (str[0] == c)
			count--;
		if (str[len - 1] == c)
			count--;
	}
	return (count);
}

static void	norme(const char *str, char *str2, int i[4], char c)
{
	if (str[i[0]] == c)
	{
		if (i[0] != 0 && str[i[0] - 1] != ' ')
			str2[i[1]++] = ' ';
		str2[i[1]] = c;
		if (i[0] != (i[3] - 1) && str[i[0] + 1] != ' ')
			str2[++i[1]] = ' ';
	}
	else
		str2[i[1]] = str[i[0]];
}

char		*ft_str_spacearround(const char *str, char c)
{
	char	*str2;
	int		i[4];

	i[0] = -1;
	i[1] = 0;
	if (!str)
		return (NULL);
	i[3] = ft_strlen(str);
	i[2] = get_nb_space(str, c, i[3]);
	str2 = malloc(sizeof(char) * (i[3] + i[2] + 1));
	while (str[++i[0]])
	{
		norme(str, str2, i, c);
		i[1]++;
	}
	str2[i[1]] = '\0';
	return (str2);
}
