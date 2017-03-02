/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:49:33 by bbetz             #+#    #+#             */
/*   Updated: 2016/08/10 21:54:51 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_file(char *av, char ***map)
{
	int		fd;
	int		nb_return;
	int		i;
	char	*line;

	i = 0;
	nb_return = 0;
	if ((fd = open(av, O_RDWR)) < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		nb_return++;
	}
	ft_strdel(&line);
	close(fd);
	if (!(*map = (char**)malloc(sizeof(char*) * (nb_return + 1))))
		return (0);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &((*map)[i])) > 0)
		i++;
	close(fd);
	(*map)[i] = NULL;
	return (1);
}
