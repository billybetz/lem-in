/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:28:02 by bbetz             #+#    #+#             */
/*   Updated: 2016/03/28 16:02:40 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INIT_I_K_0 k = 0; i = 0

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s || s[0] == '\0')
		return (ft_strdup("\0"));
	INIT_I_K_0;
	j = ft_strlen(s);
	while (ft_isspace(s[i]) == 1)
		i++;
	if (s[i] == '\0')
		return (ft_strdup("\0"));
	while (ft_isspace(s[j - 1]) == 1)
		j--;
	if (!(str = malloc(sizeof(char) * (j - i) + 1)))
		return (NULL);
	while (i < j)
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
