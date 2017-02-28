/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:26:35 by bbetz             #+#    #+#             */
/*   Updated: 2016/01/23 16:15:54 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INCREMENTE_I_SIZE i++; size++
#define DECL_I_J_NBWORDS int i; int j; int nb_words

static int	count_words(const char *str, char c)
{
	int nb_word;
	int i;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			nb_word++;
		}
	}
	return (nb_word);
}

static char	*ft_next_word(const char *s, int i, char c)
{
	char	*word;
	int		size;

	if (!s)
		return (NULL);
	size = 0;
	while (s && s[i] != c && s[i])
	{
		INCREMENTE_I_SIZE;
	}
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	i -= size;
	size = 0;
	while (s[i] != c && s[i])
	{
		word[size] = s[i];
		INCREMENTE_I_SIZE;
	}
	word[size] = '\0';
	return (word);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;

	DECL_I_J_NBWORDS;
	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	tab = (char**)malloc(sizeof(char*) * (nb_words + 1));
	if (!tab)
		return (NULL);
	while (nb_words > 0)
	{
		if (s[i] == c)
			i++;
		else
		{
			tab[j] = ft_next_word(s, i, c);
			i += ft_strlen(tab[j]);
			nb_words--;
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
