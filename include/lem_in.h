/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:38:22 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/27 01:40:13 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <../libft/include/libft.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_room	t_room;
typedef struct s_link	t_link;

struct					s_link
{
	t_room	*room;
	t_link	*next;
};

struct					s_room
{
	char	*name;
	int		ant_name;
	int		nb_ants;
	int		dist_point;
	int		coord[2];

	int		start;
	int		end;

	t_link	*connection;
	t_room	*next;
};

typedef struct			s_env
{
	char	**original_map;
	t_room	*start;
	t_room	**paths;
	int		nb_ants;
	int		arrive_ants;
	int		unique_path;
	int		print_path;
	int		print_connection;
}						t_env;

/*
**	=============	**
**	  display.c		**
**	=============	**
*/
void					moove_ants_in_paths(t_env *env);
/*
**	===========	**
**	  clear.c	**
**	===========	**
*/
char					**take_off_unknow_commands(t_env *e, char **input);
char					**take_off_comments(char **input);
/*
**	===========	**
**	  clear2.c	**
**	===========	**
*/
void					free_paths(t_room **p);
void					free_start(t_room *r);
void					clear_path(t_room ***paths, int i);
/*
**	===========	**
**	  check.c	**
**	===========	**
*/
int						check_if_name_exist(char *name, t_env env);
int						check_name_validity(char *name);
int						check_if_connect_exist(char *n1, char *n2, t_env env);
/*
**	===========	**
**	  bonus.c	**
**	===========	**
*/
void					print_path(t_env env);
void					print_room_list(t_env env);
/*
**	==============	**
**	  parsing.c		**
**	==============	**
*/
int						parse_map(char **map, t_env *env);
/*
**	==============	**
**	  parsing2.c	**
**	==============	**
*/
int						get_connection(char *line, t_env *env);
int						add_connection(t_env *env, char *name1, char *name2);
t_link					*create_maillon_connection(t_room *room);
int						get_room(char *line, t_env *env, int s, int e);
/*
**	===========	**
**	  solve.c	**
**	===========	**
*/
int						apply_dist_points(t_env env);
int						find_valid_paths(t_env *env);
/*
**	===========	**
**	  solve2.c	**
**	===========	**
*/
int						count_max_path(t_env *env);
void					get_all_smaller_path(t_room *start, t_env *env);
int						get_smallest_dist(t_room *room);
t_room					*create_maillon_room(char *n, int s, int e, int c[2]);
/*
**	===========	**
**	  solve3.c	**
**	===========	**
*/
void					add_room_to_paths(int i, t_room *r, t_room ***paths);

#endif
