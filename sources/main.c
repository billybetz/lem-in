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
}

void	take_off_unknow_commands(char ***input)
{
	int		i[3];
	char	**str;

	i[2] = ft_get_size_tab((void **)(*input));
	i[1] = 0;
	i[0] = -1;
	while ((*input)[++i[0]] != NULL)
	{
		if ((*input)[i[0]][0] == '#' && ft_strcmp((*input)[i[0]], "##start") &&
		ft_strcmp((*input)[i[0]], "##end"))
			i[1]++;
	}
	str = malloc(sizeof(char *) * (i[2] - i[1] + 1));
	i[0] = -1;
	i[1] = 0;
	while((*input)[++i[0]])
	{
		if ((*input)[i[0]][0] != '#' || !ft_strcmp((*input)[i[0]], "##start") ||
			!ft_strcmp((*input)[i[0]], "##end"))
		{
			str[i[1]] = ft_strdup((*input)[i[0]]);
			i[1]++;
		}
	}
	str[i[1]] = NULL;
	ft_free_double_pointer((void ***)input);
	*input = str;
}

void	take_off_comments(char ***input)
{
	int		i[3];
	char	**str;

	i[2] = ft_get_size_tab((void **)(*input));
	i[1] = 0;
	i[0] = -1;
	while ((*input)[++i[0]] != NULL)
	{
		if ((*input)[i[0]][0] == '#' && (*input)[i[0]][0] != '#')
			i[1]++;
	}
	str = malloc(sizeof(char *) * (i[2] - i[1] + 1));
	i[0] = -1;
	i[1] = 0;
	while((*input)[++i[0]])
	{
		if ((*input)[i[0]][0] != '#' || (*input)[i[0]][1] == '#')
		{
			str[i[1]] = ft_strdup((*input)[i[0]]);
			i[1]++;
		}
	}
	str[i[1]] = NULL;
	ft_free_double_pointer((void ***)input);
	*input = str;
}

void	ft_strtabtrim(char ***input)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_get_size_tab((void **)*input) + 1));
	while ((*input)[i])
	{
		tab[i] = ft_strtrim((*input)[i]);
		i++;
	}
	tab[i] = NULL;
	*input = ft_strtabdup((const char **)tab);
	ft_free_double_pointer((void ***)&tab);
}

void	free_anthill(t_env *e)
{
	t_room *tmp;

	ft_free_double_pointer((void***)&(e->original_map));
	if (!e->start)
		return ;
	while (e->start->next)
	{
		tmp = e->start->next;
		ft_strdel(&(e->start->name));
		free(e->start->connection);
		e->start->connection = NULL;
		e->start = tmp;
	}
	ft_strdel(&(e->start->name));
	free(e->start->connection);
	e->start->connection = NULL;
	free(e->start);
	e->start = NULL;
}

char	**get_map(int ac, char *file_name, t_env *env)
{
	char **map;

	map = NULL;
	if (ac == 1)
		ft_get_stdin(&map);
	else
		ft_get_file(file_name, &map);
	env->original_map = ft_strtabdup((const char **)map);
	ft_strtabtrim(&map);
	take_off_comments(&map);
	take_off_unknow_commands(&map);
	return (map);
}

int		main(int ac, char **av)
{
	char **map;
	t_env env;

	env.start = NULL;
	if (ac > 2)
		return (ft_error_msg("ERROR", 0));
	map = get_map(ac, av[1], &env);
	// ft_print_doubletab(map);
	if (!parse_map(map, &env))
		return (ft_error_msg("ERROR", 0));
	// if (!solve_lemin(env, map))
		// return (ft_error_msg("ERROR", 0));
	// ft_print_doubletab(env.original_map);
	printf("nb : %d\n", env.nb_ants);
	ft_free_double_pointer((void***)&map);
	free_anthill(&env);
	return (0);
}