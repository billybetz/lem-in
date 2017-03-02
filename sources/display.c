/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:46:07 by bbetz             #+#    #+#             */
/*   Updated: 2017/03/01 13:46:08 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	recursive_deplacement(t_env *env, t_room **tmp, int i, t_room *tmp2, int *ant_name)
{
	if (!(tmp2->next->end))
		recursive_deplacement(env, tmp, i, tmp2->next, ant_name);
	if (tmp2->start == 1 && !(tmp2->next->nb_ants) && env->nb_ants > 0)
	{
		ft_putchar('L');
		ft_putnbr(*ant_name);
		ft_putchar('-');
		ft_putstr(tmp2->next->name);
		ft_putchar(' ');
		tmp2->next->ant_name = *ant_name;
		tmp2->next->nb_ants++;
		env->nb_ants--;
		(*ant_name)++;
	}
	else if (tmp2->nb_ants && !(tmp2->next->nb_ants))
	{
		ft_putchar('L');
		ft_putnbr(tmp2->ant_name);
		ft_putchar('-');
		ft_putstr(tmp2->next->name);
		ft_putchar(' ');
		tmp2->next->ant_name = tmp2->ant_name;
		tmp2->nb_ants--;
		tmp2->next->nb_ants++;
		if (tmp2->next->end)
		{
			tmp2->next->nb_ants = 0;
			env->arrive_ants++;
		}
	}
}

void	all_in(t_env env)
{
	int i;

	i = 1;
	while (i <= env.nb_ants)
	{
		ft_putchar('L');
		ft_putnbr(i);
		ft_putchar('-');
		ft_putstr((env.paths[0])->next->name);
		if (i < env.nb_ants)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	moove_ants_in_paths(t_env *env)
{
	t_room	**tmp;
	t_room	*tmp2;
	int		i;
	int		ant_name;
	int		nb_ants;

	nb_ants = env->nb_ants;
	env->arrive_ants = 0;
	ant_name = 1;
	if (env->unique_path)
		return (all_in(*env));
	while (env->arrive_ants < nb_ants)
	{
		i = 0;
		tmp = env->paths;
		while (tmp[i])
		{
			tmp2 = tmp[i];
			recursive_deplacement(env, tmp, i, tmp2, &ant_name);
			i++;
		}
		ft_putchar('\n');
	}
}
