/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 02:16:41 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/09 08:19:52 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	ph_sleep_think(t_pii *plato)
{
	ph_out_msg(plato, MSG_SLEEP, SLEEP);
	ph_wait(plato, plato->time_to_sleep);
	ph_out_msg(plato, MSG_THINK, THINK);
}

void
	ph_first_wait(t_pii *plato)
{
	if (!(plato->number_of_philosophers % 2))
	{
		if (!(plato->id % 2))
			usleep(plato->time_to_eat * 1000);
	}
	else
	{
		if (!(plato->id % 3))
			usleep(plato->time_to_eat * 1000);
		else if (plato->id % 3 == 1)
			usleep(plato->time_to_eat * 2000);
	}
}

void
	ph_wait(t_pii *plato, int time)
{
	long long	start;
	long long	now;

	start = get_time();
	while (42)
	{
		now = get_time();
		if (plato->time_to_die <= now - plato->lasteat)
		{
			ph_out_msg(plato, MSG_DIED, DIED);
			pthread_mutex_lock(plato->died);
			*plato->fin = true;
			pthread_mutex_unlock(plato->died);
			return ;
		}
		if (time <= now - start)
			return ;
		usleep(100);
	}
}

int
	ph_eat(t_pii *plato)
{
	ph_out_msg(plato, MSG_EAT, EAT);
	pthread_mutex_lock(plato->died);
	++plato->eat_cnt;
	if (plato->is_must_eat
		&& plato->eat_cnt == plato->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(plato->eat);
		++*plato->meal_fin;
		pthread_mutex_unlock(plato->eat);
	}
	if (*(plato->meal_fin) == plato->number_of_philosophers)
		*plato->fin = true;
	pthread_mutex_unlock(plato->died);
	plato->lasteat = get_time();
	ph_wait(plato, plato->time_to_eat);
	pthread_mutex_unlock(plato->left);
	pthread_mutex_unlock(plato->right);
	return (0);
}

int
	ph_take_fork(t_pii *plato)
{
	if (plato->id % 2)
		pthread_mutex_lock(plato->right);
	else
	{
		usleep(200);
		pthread_mutex_lock(plato->left);
	}
	ph_out_msg(plato, MSG_FORK, FORK);
	if (plato->id % 2)
	{
		usleep(200);
		pthread_mutex_lock(plato->left);
	}
	else
		pthread_mutex_lock(plato->right);
	ph_out_msg(plato, MSG_FORK, FORK);
	return (0);
}
