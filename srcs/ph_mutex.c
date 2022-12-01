/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 01:04:58 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/09 08:19:02 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	ph_mutex_destroy(t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ph->number_of_philosophers)
	{
		pthread_mutex_destroy(&ph->fork[i]);
	}
	pthread_mutex_destroy(&ph->died);
	pthread_mutex_destroy(&ph->eat);
}

int
	ph_init_eat(t_philo *ph)
{
	int	i;

	if (pthread_mutex_init(&ph->eat, NULL))
		return (error_msg(ERR_MUTEX));
	ph->meal_fin = 0;
	if (pthread_mutex_init(&ph->died, NULL))
		return (error_msg(ERR_MUTEX));
	i = -1;
	while (++i < ph->number_of_philosophers)
	{
		ph->men[i].eat = &ph->eat;
		ph->men[i].meal_fin = &ph->meal_fin;
		ph->men[i].died = &ph->died;
	}
	return (0);
}

int
	ph_init_fork(t_philo *ph)
{
	int	i;

	ph->fork = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * ph->number_of_philosophers);
	if (!ph->fork)
		return (error_msg(ERR_MALLOC));
	i = -1;
	while (++i < ph->number_of_philosophers)
		if (pthread_mutex_init(&ph->fork[i], NULL))
			return (error_msg(ERR_MUTEX));
	i = -1;
	while (++i < ph->number_of_philosophers)
	{
		ph->men[i].right = &ph->fork[i];
		if (i == ph->number_of_philosophers - 1)
			ph->men[i].left = &ph->fork[0];
		else
			ph->men[i].left = &ph->fork[i + 1];
	}
	return (0);
}
