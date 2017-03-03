/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:37:26 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/27 01:37:27 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	======================	**
**		i[0] : i			**
**		i[1] : nb_start		**
**		i[2] : nb_end		**
**	======================  **
*/

static int	parse_connection(int i[3], char **line, char **map, t_env *env)
{
	if (i[1] != 1 || i[2] != 1 || !map[i[0]])
		return (0);
	while (map[i[0]])
	{
		line = ft_str_to_tab(map[i[0]]);
		if (!line[0] || line[1] || ft_str_count_c(line[0], '-') != 1 ||
			!get_connection(line[0], env))
		{
			ft_free_double_pointer((void ***)&line);
			return (0);
		}
		ft_free_double_pointer((void ***)&line);
		i[0]++;
	}
	return (1);
}

static int	parse_map3(int i[3], char ***line, char **map, t_env *env)
{
	if (!ft_strcmp(map[i[0]], "##path"))
		env->print_path = 1;
	else if (!ft_strcmp(map[i[0]], "##connect"))
		env->print_connection = 1;
	else if ((*line)[0] && !(*line)[1])
	{
		ft_free_double_pointer((void ***)line);
		return (3);
	}
	else
	{
		if (!map[i[0]] || ft_count_words(map[i[0]]) != 3 ||
			!get_room(map[i[0]], env, 0, 0))
		{
			ft_free_double_pointer((void ***)line);
			return (0);
		}
	}
	ft_free_double_pointer((void ***)line);
	return (1);
}

static int	parse_map2(int i[3], char ***line, char **map, t_env *env)
{
	if (!ft_strcmp(map[i[0]], "##start"))
	{
		i[1]++;
		if (!map[++i[0]] || ft_count_words(map[i[0]]) != 3 ||
			!get_room(map[i[0]], env, 1, 0))
		{
			ft_free_double_pointer((void ***)line);
			return (0);
		}
		ft_free_double_pointer((void ***)line);
		return (1);
	}
	else if (!ft_strcmp(map[i[0]], "##end"))
	{
		i[2]++;
		if (!map[++i[0]] || ft_count_words(map[i[0]]) != 3 ||
			!get_room(map[i[0]], env, 0, 1))
		{
			ft_free_double_pointer((void ***)line);
			return (0);
		}
		ft_free_double_pointer((void ***)line);
		return (1);
	}
	return (2);
}

static void	init_parse(int i[3])
{
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
}

int			parse_map(char **map, t_env *env)
{
	char	**line;
	int		i[3];
	int		ret;

	init_parse(i);
	if (!ft_str_is_number(map[0]) || (env->nb_ants = ft_atoi(map[0])) < 0)
		return (0);
	while (map[++i[0]])
	{
		line = ft_str_to_tab(map[i[0]]);
		if (!(*line)[0])
			return (0);
		if ((ret = parse_map2(i, &line, map, env)) == 0)
			return (0);
		if (ret == 2)
		{
			if ((ret = parse_map3(i, &line, map, env)) == 0)
				return (0);
			if (ret == 3)
				break ;
		}
	}
	if (parse_connection(i, line, map, env) == 0)
		return (0);
	return (1);
}
