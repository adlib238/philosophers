/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_observer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:44:40 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/08 12:09:18 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	*ph_observer(void *p)
{
	t_philo	*ph;
	int		i;

	ph = p;
	while (!ph->fin)
	{
		i = -1;
		while (++i < ph->number_of_philosophers)
		{
			if (!ph->men[i].lasteat)
				continue ;
			if (ph->men[i].time_to_die <= get_time() - ph->men[i].lasteat)
			{
				ph_out_msg(&ph->men[i], MSG_DIED, DIED);
				pthread_mutex_lock(&ph->died);
				ph->fin = true;
				pthread_mutex_unlock(&ph->died);
				return (NULL);
			}
		}
		usleep(200);
	}
	return (NULL);
}
