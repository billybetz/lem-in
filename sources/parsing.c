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

#include "lem-in.h"

void	print_room_list(t_env env)
{
	t_room *tmp;
	t_link *tmp2;

	tmp = env.start;
	while (tmp)
	{
		printf("name : %s\n", tmp->name);
		tmp2 = tmp->connection;
		while (tmp2)
		{
			printf(" - connexion avec %s\n", tmp2->room->name);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

int			check_if_name_exist(char *name, t_env env)
{
	t_room	*tmp;

	tmp = env.start;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_room		*create_maillon_room(char *name, int start, int end, int coord[2])
{
	t_room *room;

	room = malloc(sizeof(t_room));
	room->name = ft_strdup(name);
	room->start = start;
	room->end = end;
	room->coord[0] = coord[0];
	room->coord[1] = coord[1];
	room->connection = NULL;
	room->next = NULL;
	return (room);
}

int		check_name_validity(char *name)
{
	if (!name || !name[0])
		return (0);
	if (name[0] == 'L' || name[0] == '#')
		return (0);
	if (ft_strfindchar(name, '-') != -1)
		return (0);
	return (1);
}

int		get_room(char *line, t_env *env, int s, int e)
{
	char	**to_tab;
	t_room	*tmp;
	int		coord[2];

	tmp = env->start;
	to_tab = ft_str_to_tab(line);
	if (!ft_str_is_number(to_tab[1]) || !ft_str_is_number(to_tab[2]))
		return (0);
	if (!check_name_validity(to_tab[0]))
		return (0);
	coord[0] = ft_atoi(to_tab[1]);
	coord[1] = ft_atoi(to_tab[2]);
	if (check_if_name_exist(to_tab[0], *env))
		return (0);
	if (!tmp)
		env->start = create_maillon_room(to_tab[0], s, e, coord);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_maillon_room(to_tab[0], s, e, coord);
	}
	ft_free_double_pointer((void ***)&to_tab);
	return (1);
}

t_link	*create_maillon_connection(t_room *room)
{
	t_link	*link;
	
	link = malloc(sizeof(t_link));
	link->room = room;
	link->next = NULL;
	return (link);
}

int		add_connection(t_env *env, char *name1, char *name2)
{
	t_room	*tmp;
	t_room	*tmp2;
	t_link	*link_tmp;
	t_link	*link_tmp2;

	tmp = env->start;
	tmp2 = env->start;
	if (!tmp)
		return (0);
	while (ft_strcmp(tmp->name, name1))
		tmp = tmp->next;
	while (ft_strcmp(tmp2->name, name2))
		tmp2 = tmp2->next;
	if (!tmp || !tmp2)
		return (0);
	if (!(link_tmp = tmp->connection))
		tmp->connection = create_maillon_connection(tmp2);
	else
	{
		while (link_tmp->next)
			link_tmp = link_tmp->next;
		link_tmp->next = create_maillon_connection(tmp2);
	}
	if (!(link_tmp2 = tmp2->connection))
		tmp2->connection = create_maillon_connection(tmp);
	else
	{
		while (link_tmp2->next)
			link_tmp2 = link_tmp2->next;
		link_tmp2->next = create_maillon_connection(tmp);
	}
	return (1);
}

int		check_if_connect_exist(char *name1, char *name2, t_env env)
{
	t_room	*tmp;
	t_link	*tmp2;

	tmp = env.start;
	while (tmp && ft_strcmp(tmp->name, name1))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	tmp2 = tmp->connection;
	while (tmp2 && ft_strcmp(tmp2->room->name, name2))
		tmp2 = tmp2->next;
	if (!tmp2)
		return (0);
	return (1);
}

int		get_connection(char *line, t_env *env)
{
	char 	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, '-');
	if (!tab || !tab[0] || !tab[1] || tab[2])
		return (0);
	if (!check_if_name_exist(tab[0], *env) ||
		!check_if_name_exist(tab[1], *env))
		return (0);
	if (check_if_connect_exist(tab[0], tab[1], *env))
	{
		ft_free_double_pointer((void ***)&tab);
		return (1);
	}
	if (!add_connection(env, tab[0], tab[1]))
		return (0);
	ft_free_double_pointer((void ***)&tab);
	return (1);
}

int		count_tiret(char *s)
{
	int nb;
	int i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == '-')
			nb++;
		i++;
	}
	return (nb);
}

int		parse_map(char **map, t_env *env)
{
	char **line;
	int nb_start_end[2];
	int i;

	i = 0;
	nb_start_end[0] = 0;
	nb_start_end[1] = 0;
	if (!ft_str_is_number(map[0]))
		return (0);
	if ((env->nb_ants = ft_atoi(map[0])) < 0)
		return (0);
	while (map[++i])
	{
		line = ft_str_to_tab(map[i]);
		if (!line[0])
			return (0);
		if (!ft_strcmp(map[i], "##start"))
		{
			nb_start_end[0]++;
			if (!map[++i] || ft_count_words(map[i]) != 3)
				return (0);
			if (!get_room(map[i], env, 1, 0))
				return (0);
		}
		else if (!ft_strcmp(map[i], "##end"))
		{
			nb_start_end[1]++;
			if (!map[++i] || ft_count_words(map[i]) != 3)
				return (0);
			if (!get_room(map[i], env, 0, 1))
				return (0);
		}
		else if (line[0] && !line[1])
		{
			ft_free_double_pointer((void ***)&line);
			break ;
		}
		else
		{
			if (!map[i] || ft_count_words(map[i]) != 3)
				return (0);
			if (!get_room(map[i], env, 0, 0))
				return (0); 
		}
		ft_free_double_pointer((void ***)&line);
	}
	if (nb_start_end[0] != 1 || nb_start_end[1] != 1)
		return (0);
	if (!map[i])
		return (0);
	while (map[i])
	{
		line = ft_str_to_tab(map[i]);
		if (!line[0] || line[1])
			return (0);
		if (count_tiret(line[0]) != 1)
			return (0);
		if (!get_connection(line[0], env))
				return (0);
		ft_free_double_pointer((void ***)&line);
		i++;
	}
	print_room_list(*env);
	return (1);
}
