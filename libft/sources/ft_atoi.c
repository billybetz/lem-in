/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:07:06 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/24 19:11:48 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INIT result = 0; sign = 1; cpt = 0

int		ft_atoi(const char *str)
{
	int			result;
	int			sign;
	int			cpt;

	INIT;
	while (str[cpt] == ' ' || str[cpt] == '\n' || str[cpt] == '\t' ||
			str[cpt] == '\f' || str[cpt] == '\v' || str[cpt] == '\r')
		cpt++;
	sign = (str[cpt] == '-') ? -1 : 1;
	if (str[cpt] == '-')
		cpt++;
	else if (str[cpt] == '+')
		cpt++;
	while (str[cpt] == '0')
		cpt++;
	while (str[cpt] != '\0' && str[cpt] <= '9' && str[cpt] >= '0')
	{
		result = result * 10 + str[cpt] - '0';
		cpt++;
	}
	if (result == I_MAX)
		return (I_MAX);
	if (result == I_MIN)
		return (I_MIN);
	return (result * sign);
}
