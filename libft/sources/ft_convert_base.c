/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:07:41 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/16 18:09:11 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_base(char ch, char *base)
{
	int		count;

	count = 0;
	while (base[count] != '\0')
	{
		if (ch == base[count])
			return (count);
		count++;
	}
	return (-1);
}

static int	ft_atoi_base(char *str, char *base)
{
	int		number;
	int		negatif;

	negatif = 1;
	if (*str == '-' || *str == '+')
	{
		negatif = (*str == '-') ? -1 : 1;
		str++;
	}
	number = 0;
	while (*str != '\0')
	{
		number *= ft_strlen(base);
		if (ft_find_base(*str, base) == -1)
			return (0);
		number += (ft_find_base(*str, base));
		str++;
	}
	return (number * negatif);
}

static void	ft_len_nb(int *j, int *i, char *base_to, int n)
{
	while ((unsigned int)(n / *j) > ft_strlen(base_to) - 1)
	{
		*j *= ft_strlen(base_to);
		(*i)++;
	}
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		j;
	char	*res;
	int		i;

	j = 1;
	i = 0;
	nb = ft_atoi_base(nbr, base_from);
	ft_len_nb(&j, &i, base_to, nb);
	res = (char*)malloc(sizeof(char) * (i + ((nb < 0) ? 1 : 0)));
	i = (nb < 0) ? 1 : 0;
	res[0] = '-';
	j = (nb < 0) ? j * ft_strlen(base_to) : j;
	nb = (nb < 0) ? -nb : nb;
	while (j > 0)
	{
		res[i] = base_to[(nb / j) % ft_strlen(base_to)];
		j /= ft_strlen(base_to);
		i++;
	}
	res[i] = '\0';
	return (res);
}
