/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_pram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:35:58 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/10 21:15:30 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	men_def(t_pii *plato)
{
	plato->number_of_philosophers = 0;
	plato->time_to_die = 0;
	plato->time_to_eat = 0;
	plato->time_to_sleep = 0;
	plato->number_of_times_each_philosopher_must_eat = 0;
	plato->is_must_eat = false;
	plato->id = 0;
	plato->eat_cnt = 0;
	plato->meal_fin = NULL;
	plato->fin = NULL;
	plato->lasteat = 0;
	plato->start = get_time();
	plato->left = NULL;
	plato->right = NULL;
	plato->eat = NULL;
	plato->died = NULL;
}

int
	men_init_set(t_philo *ph)
{
	t_pii	plato;
	int		i;

	ph->men = (t_pii *)malloc(sizeof(t_pii) * ph->number_of_philosophers);
	if (!ph->men)
		return (error_msg(ERR_MALLOC));
	men_def(&plato);
	plato.number_of_philosophers = ph->number_of_philosophers;
	plato.time_to_die = ph->time_to_die;
	plato.time_to_eat = ph->time_to_eat;
	plato.time_to_sleep = ph->time_to_sleep;
	plato.number_of_times_each_philosopher_must_eat
		= ph->number_of_times_each_philosopher_must_eat;
	plato.is_must_eat = ph->is_must_eat;
	i = -1;
	while (++i < ph->number_of_philosophers)
	{
		plato.id = i + 1;
		ph->men[i] = plato;
		ph->men[i].fin = &ph->fin;
		ph->men[i].fork = &ph->silver[i];
	}
	return (0);
}

int
	check_pram(t_philo *ph)
{
	if (ph->number_of_philosophers > 200)
		return (1);
	if (ph->time_to_die < 60)
		return (1);
	if (ph->time_to_eat < 60)
		return (1);
	if (ph->time_to_sleep < 60)
		return (1);
	if (ph->is_must_eat
		&& ph->number_of_times_each_philosopher_must_eat < 1)
		return (1);
	return (0);
}

int
	ph_init_set(int ac, char *av[], t_philo *ph)
{
	int	i;

	ph->number_of_philosophers = ft_atoi(av[1]);
	ph->time_to_die = ft_atoi(av[2]);
	ph->time_to_eat = ft_atoi(av[3]);
	ph->time_to_sleep = ft_atoi(av[4]);
	ph->number_of_times_each_philosopher_must_eat = 0;
	ph->is_must_eat = false;
	if (ac == 6)
	{
		ph->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		ph->is_must_eat = true;
	}
	ph->men = NULL;
	ph->fork = NULL;
	ph->fin = false;
	ph->observer = NULL;
	ph->meal_fin = 0;
	ph->silver = (int *)malloc(sizeof(int) * ph->number_of_philosophers);
	if (!ph->silver)
		return (error_msg(ERR_MALLOC));
	i = -1;
	while (++i < ph->number_of_philosophers)
		ph->silver[i] = i;
	return (0);
}

int
	ph_init_pram(int ac, char *av[], t_philo *ph)
{
	ph_init_set(ac, av, ph);
	if (check_pram(ph))
		return (print_usage());
	if (ph->number_of_philosophers == 1)
		return (ph_solo(ph));
	if (men_init_set(ph))
		return (1);
	return (0);
}
