/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:27:18 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/20 22:16:44 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		count;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == to_find[0])
		{
			count = 0;
			while (str[count] != '\0' && to_find[count] != '\0')
			{
				if (str[count] != to_find[count])
					break ;
				count++;
			}
			if (to_find[count] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
