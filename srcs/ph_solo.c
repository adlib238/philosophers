/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_solo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:22:07 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/08 11:51:29 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	ph_solo(t_philo *ph)
{
	printf(YELLOW"%lld %d %s\n"RESET,
		get_time(), 1, MSG_FORK);
	printf(RED "%lld %d %s\n" RESET,
		get_time() + ph->time_to_die, 1, MSG_DIED);
	return (1);
}
