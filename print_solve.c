/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:10:27 by icanker           #+#    #+#             */
/*   Updated: 2020/11/10 14:10:33 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			count_aunts_for_pathes(t_path **pathes, t_lemin *lem)
{
	int i;

	i = 0;
	while (i < lem->ins)
		pathes[i++]->count_ants = 0;
	while (1)
	{
		i = 0;
		if (i == lem->ins)
			return ;
		while (i != lem->ins)
		{
			if (lem->UsableAunts >= lem->num_ants)
				return ;
			if (pathes[i]->length + pathes[i]->count_ants
				< lem->stage)
			{
				pathes[i]->count_ants++;
				lem->UsableAunts++;
			}
			i++;
		}
		lem->stage++;
	}
}

t_room			*findnext(t_path *path, t_room *this_room)
{
	int i;

	i = 0;
	while (i != path->length - 1)
	{
		if (!strcmp(path->sh[i]->name, this_room->name))
			return (path->sh[i + 1]);
		i++;
	}
	return (this_room);
}

int				count_iterations(t_lemin *lem, t_path **pathes)
{
	int i;
	int max;

	i = 0;
	max = -1;
	while (i != lem->ins)
	{
		if (max < pathes[i]->length - 1 + pathes[i]->count_ants && \
				pathes[i]->count_ants != 0)
			max = pathes[i]->length - 1 + pathes[i]->count_ants;
		i++;
	}
	return (max);
}

static	void	do_iteration(int *j, t_lemin *lem, t_path **pathes, int *a_i)
{
	while (lem->ants[*a_i].VisitedRoom && *a_i <= lem->num_ants - 1)
	{
		if (ft_strcmp(lem->ants[*a_i].VisitedRoom->name, lem->end_room->name))
		{
			lem->ants[*a_i].VisitedRoom = findnext(lem->ants[*a_i].UsedPath,
				lem->ants[*a_i].VisitedRoom);
			ft_printf("L%d-%s ", lem->ants[*a_i].nbr,
				lem->ants[*a_i].VisitedRoom->name);
		}
		(*a_i)++;
	}
	*j = 0;
	while (*j != lem->ins && *a_i <= lem->num_ants - 1)
	{
		if (pathes[*j]->count_ants > 0)
		{
			lem->ants[*a_i].UsedPath = pathes[*j];
			lem->ants[*a_i].VisitedRoom = pathes[*j]->sh[1];
			pathes[*j]->count_ants -= 1;
			ft_printf("L%d-%s ",
				lem->ants[*a_i].nbr, lem->ants[*a_i].VisitedRoom->name);
			(*a_i)++;
		}
		(*j)++;
	}
}

void			print_solve(t_lemin *lem, t_path **pathes)
{
	int i;
	int max;
	int j;
	int a_i;

<<<<<<< HEAD
	max = count_iterations(lem, mass_pathes);
=======
	max = count_iterations(lem, pathes);
>>>>>>> 08cbd88b2d060af364cce5b7bc4cfda238c7049a
	i = 0;
	while (i != max)
	{
		a_i = 0;
		ft_putstr("\n");
		do_iteration(&j, lem, pathes, &a_i);
		i++;
	}
<<<<<<< HEAD
	if (lem->num_lines == 1)
		lem->color ? ft_printf(GRN"Count of lines: %d\n"RST, max) : \
						ft_printf("Count of lines: %d\n", max);
}
=======
}
>>>>>>> 08cbd88b2d060af364cce5b7bc4cfda238c7049a