/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 01:49:38 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/08 11:07:36 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	*ph_task(void *p)
{
	t_pii	*plato;

	plato = p;
	plato->lasteat = get_time();
	while (!*plato->fin)
	{
		ph_take_fork(plato);
		ph_eat(plato);
		ph_sleep_think(plato);
	}
	return (NULL);
}

void
	ph_loop(t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ph->number_of_philosophers)
		pthread_create(&ph->men[i].thread, NULL, &ph_task, (void *)&ph->men[i]);
	pthread_create(&ph->observer, NULL, &ph_observer, (void *)ph);
	i = -1;
	while (++i < ph->number_of_philosophers)
		pthread_join(ph->men[i].thread, NULL);
	pthread_join(ph->observer, NULL);
}
