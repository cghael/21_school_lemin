//
// Created by  Anton Gorobets on 30.09.2020.
//

#include "lemin.h"

static t_step	*ft_init_n_add_step(t_print **print, int ant, int room)
{
	t_step	*tmp;
	t_step	*begin_step;
	t_print	*begin_print;

	tmp = ft_memalloc(sizeof(t_step));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->ant = ant;
	tmp->room = room;
	begin_print = *print;
	while (begin_print->next)
		begin_print = begin_print->next;
	if (!begin_print->step)
		begin_print->step = tmp;
	else
	{
		begin_step = begin_print->step;
		while (begin_step->next)
			begin_step = begin_step->next;
		begin_step->next = tmp;
	}
	return (tmp);
}

static t_print	*ft_init_n_add_print(t_print **print)
{
	t_print *tmp;
	t_print *begin;

	tmp = ft_memalloc(sizeof(t_print));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->step = NULL;
	if (!*print)
		*print = tmp;
	else
	{
		begin = *print;
		while (begin->next)
			begin = begin->next;
		begin->next = tmp;
	}
	return (tmp);
}

static int		ft_ants_tap_tap(t_ant *ants, int len, t_lemin *lemin)
{
	int		i;
	int		res;

	res = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (ants[i].ant)
		{
			ants[i + 1].ant = ants[i].ant;
			if (!(ft_init_n_add_step(&lemin->print, ants[i + 1].ant, ants[i+1].room)))
				return (-1);
//			ft_printf("L%d-%s ", ants[i + 1].ant, lemin->graph[ants[i+1].room].name);
			ants[i].ant = 0;
			if (i + 2 == len)
			{
				res++;
				ants[i + 1].ant = 0;
			}
		}
		i--;
	}
	return (res);
}

int			ft_ants_mooving(t_lemin *lemin, t_tracks *tracks)
{
	int			ant_number;
	int			ant_start;
	int			ant_finish;
	t_tracks	*tmp;
	int			res;

	ant_number = 1;
	ant_start = lemin->ants;
	ant_finish = 0;
	while (ant_finish < lemin->ants)
	{
		tmp = tracks;
		if (!(ft_init_n_add_print(&lemin->print)))
			return (EXIT_FAILURE);
		while (tmp)
		{
//			if (!(ft_init_n_add_print(&lemin->print)))
//				return (EXIT_FAILURE);
			if (tmp->running_ants)
			{
				res = ft_ants_tap_tap(tmp->ants, tmp->len, lemin);
				if (res < 0)
					return (EXIT_FAILURE);
				else if (res > 0)
				{
					ant_finish++;
					tmp->running_ants--;
				}
			}
			if (tmp->ant_num && ant_start)
			{
				tmp->ants[0].ant = ant_number;
				tmp->running_ants++;
				if (!(ft_init_n_add_step(&lemin->print, tmp->ants[0].ant, tmp->ants[0].room)))
					return (EXIT_FAILURE);
//				ft_printf("L%d-%s ", tmp->ants[0].ant, lemin->graph[tmp->ants[0].room].name);
				ant_number++;
				ant_start--;
				tmp->ant_num--;
			}
			tmp = tmp->next;
		}
//		ft_printf("\n");
	}
	return (EXIT_SUCCESS);
}
