/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:38:22 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/27 01:40:13 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <../libft/include/libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_room t_room;
typedef struct s_link t_link;

struct	s_link
{
	t_room *room;
	t_link *next;
};

struct	s_room
{
	char	*name;
	int		ant_name;
	int		nb_ants;
	int		dist_point;
	int		coord[2];

	int		start;
	int		end;

	t_link *connection;
	t_room *next;
};

typedef struct	s_env
{
	char		**original_map;
	t_room		*start;
	t_room		**paths;
	int			nb_ants;
	int			arrive_ants;
	int			unique_path;
	int			print_path;
	int			print_connection;
}				t_env;

int		parse_map(char **map, t_env *env);
int		apply_dist_points(t_env env);
void	print_room_list(t_env env);
int		find_valid_paths(t_env *env);
void	print_path(t_env env);
t_room	*create_maillon_room(char *name, int start, int end, int coord[2]);
void	moove_ants_in_paths(t_env *env);