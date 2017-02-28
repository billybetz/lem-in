/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:57:30 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/16 12:19:28 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i + 1);
}

static int	place_line(char **line, char **stock)
{
	int		i;
	int		y;
	char	*tmp;

	y = 0;
	i = -1;
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(*stock) + 1))))
		return (-1);
	if (!(*line = (char*)malloc(sizeof(char) * (len(*stock) + 1))))
		return (-1);
	while (*stock && (*stock)[++i] && (*stock)[i] != '\n')
		(*line)[i] = (*stock)[i];
	(*line)[i] = '\0';
	if ((*stock)[i])
		i++;
	while ((*stock)[i])
		tmp[y++] = (*stock)[i++];
	tmp[y] = '\0';
	free(*stock);
	*stock = ft_strdup(tmp);
	free(tmp);
	return (0);
}

static int	str_add(char **stock, char buff[BUFF_SIZE])
{
	int		i;
	int		y;
	char	*tmp;

	y = 0;
	i = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(*stock) + ft_strlen(buff) + 1));
	if (!tmp)
		return (-1);
	while (*stock && (*stock)[i])
	{
		tmp[i] = (*stock)[i];
		i++;
	}
	while (buff && buff[y])
	{
		tmp[i] = buff[y];
		i++;
		y++;
	}
	tmp[i] = '\0';
	free(*stock);
	*stock = ft_strdup(tmp);
	free(tmp);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	t_gnl		i;
	static char	*stock = NULL;

	i.i = -1;
	while ((i.ret = read(fd, i.buff, BUFF_SIZE)))
	{
		if (i.ret == -1)
			return (-1);
		i.buff[i.ret] = '\0';
		if (str_add(&stock, i.buff) == -1)
			return (-1);
		if ((ft_have_return(stock) == 1))
		{
			if (place_line(line, &stock) == -1)
				return (-1);
			return (1);
		}
	}
	if (stock && stock[0])
	{
		if (place_line(line, &stock) == -1)
			return (-1);
		return (1);
	}
	return (0);
}
