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

#include "lem-in.h"

void	ft_print_doubletab(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		ft_putendl(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		line_is_valid(char *str)
{
	char	**test;
	int		i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] == '#')
		return (1);
	if (!(test = ft_str_to_tab(str)) || !test[0])
	{
		ft_free_double_pointer((void ***)&test);
		return (0);
	}
	ft_free_double_pointer((void ***)&test);
	return (1);
}

char	**take_off_unknow_commands(t_env *e, char **input)
{
	int		i[3];
	char	**str;

	i[2] = ft_get_size_tab((void **)(input));
	i[1] = 0;
	i[0] = -1;
	while ((input)[++i[0]] != NULL)
	{
		if ((input)[i[0]][0] == '#' && ft_strcmp(input[i[0]], "##start") &&
		ft_strcmp(input[i[0]], "##end"))
			i[1]++;
	}
	str = malloc(sizeof(char *) * (i[2] - i[1] + 1));
	i[0] = -1;
	i[1] = 0;
	while (input[++i[0]] && line_is_valid(input[i[0]]))
	{
		if (!ft_strcmp(input[i[0]], "##connect"))
			e->print_connection = 1;
		if (!ft_strcmp(input[i[0]], "##path"))
			e->print_path = 1;
		if (input[i[0]][0] != '#' || !ft_strcmp(input[i[0]], "##start") ||
			!ft_strcmp(input[i[0]], "##end"))
		{
			str[i[1]] = ft_strdup(input[i[0]]);
			i[1]++;
		}
	}
	str[i[1]] = NULL;
	return (str);
}

char	**take_off_comments(char **input)
{
	int		i[3];
	char	**str;

	i[2] = ft_get_size_tab((void **)(input));
	i[1] = 0;
	i[0] = -1;
	while ((input)[++i[0]] != NULL)
	{
		if ((input)[i[0]][0] == '#' && (input)[i[0]][0] != '#')
			i[1]++;
	}
	str = malloc(sizeof(char *) * (i[2] - i[1] + 1));
	i[0] = -1;
	i[1] = 0;
	while ((input)[++i[0]])
	{
		if ((input)[i[0]][0] != '#' || (input)[i[0]][1] == '#')
		{
			str[i[1]] = ft_strdup((input)[i[0]]);
			i[1]++;
		}
	}
	str[i[1]] = NULL;
	return (str);
}

char	**ft_strtabtrim(char **input)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_get_size_tab((void **)input) + 1));
	while (input[i])
	{
		tab[i] = ft_strtrim(input[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	free_paths(t_room **p)
{
	t_room	*r;
	int		i;

	i = 0;
	while (p[i])
	{
		while (p[i])
		{
			r = p[i]->next;
			free(p[i]->name);
			free(p[i]);
			p[i] = r;
		}
		i++;
	}
	free(p);
}

void	free_start(t_room *r)
{
	t_room *tmp;
	t_link *co;
	t_link *co2;

	while (r)
	{
		tmp = r->next;
		co = r->connection;
		while (co)
		{
			co2 = co->next;
			free(co);
			co = co2;
		}
		free(r->name);
		free(r);
		r = tmp;
	}
}

char	**get_map(int ac, char *file_name, t_env *env)
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

int		main(int ac, char **av)
{
	char	**map;
	t_env	env;

	env.start = NULL;
	env.paths = NULL;
	env.print_path = 0;
	env.print_connection = 0;
	env.unique_path = 0;
	if (ac > 2)
		return (ft_error_msg("ERROR", 0));
	if (!(map = get_map(ac, av[1], &env)))
		return (ft_error_msg("ERROR", 0));
	if (!parse_map(map, &env))
		return (ft_error_msg("ERROR", 0));
	if (!apply_dist_points(env))
		return (0);
	if (!find_valid_paths(&env))
		return (ft_error_msg("ERROR", 0));
	ft_print_doubletab(env.original_map);
	if (env.print_connection == 1)
		print_room_list(env);
	moove_ants_in_paths(&env);
	if (env.print_path == 1)
		print_path(env);
	ft_free_double_pointer((void***)&map);
	ft_free_double_pointer((void***)&(env.original_map));
	free_start(env.start);
	free_paths(env.paths);
	return (0);
}
