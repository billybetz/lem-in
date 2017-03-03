/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:37:09 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/27 01:38:11 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**get_map(int ac, char *file_name, t_env *env)
{
	char **map;
	char **tmp;

	map = NULL;
	if (ac == 1)
		ft_get_stdin(&map);
	else
		ft_get_file(file_name, &map);
	if (!map || !map[0])
		return (NULL);
	env->original_map = ft_strtabdup((const char **)map);
	tmp = map;
	map = ft_strtabtrim(map);
	ft_free_double_pointer((void ***)&tmp);
	tmp = map;
	map = take_off_comments(map);
	ft_free_double_pointer((void ***)&tmp);
	tmp = map;
	map = take_off_unknow_commands(env, map);
	ft_free_double_pointer((void ***)&tmp);
	return (map);
}

void		init_main(t_env *env)
{
	env->start = NULL;
	env->paths = NULL;
	env->print_path = 0;
	env->print_connection = 0;
	env->unique_path = 0;
}

void		free_all(char ***map, t_env env, char ***map2)
{
	ft_free_double_pointer((void***)map);
	ft_free_double_pointer((void***)map2);
	free_start(env.start);
	free_paths(env.paths);
}

static int	main2(t_env env, char **map)
{
	if (!find_valid_paths(&env))
	{
		free_all(&map, env, &(env.original_map));
		return (ft_error_msg("ERROR", 0));
	}
	ft_print_strtab(env.original_map);
	if (env.print_connection == 1)
		print_room_list(env);
	moove_ants_in_paths(&env);
	if (env.print_path == 1)
		print_path(env);
	free_all(&map, env, &(env.original_map));
	return (0);
}

int			main(int ac, char **av)
{
	char	**map;
	t_env	env;

	init_main(&env);
	if (ac > 2)
		return (ft_error_msg("ERROR", 0));
	if (!(map = get_map(ac, av[1], &env)))
		return (ft_error_msg("ERROR", 0));
	if (!parse_map(map, &env))
	{
		free_all(&map, env, &(env.original_map));
		return (ft_error_msg("ERROR", 0));
	}
	if (!apply_dist_points(env))
	{
		free_all(&map, env, &(env.original_map));
		return (0);
	}
	main2(env, map);
	return (0);
}
