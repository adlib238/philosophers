/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:02:32 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/10 21:12:27 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	error_msg(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

int
	print_usage(void)
{
	printf("\
Usage: ./philo PN TD TE TS (EC)\n\n\
\
	PN = number of philosophers\n\
	TD = time to die\n\
	TE = time to eat\n\
	TS = time to sleep\n\
	EC = number of times each philosopher must eat\n\n\
\
	PN <= 200\n\
	TD >= 60ms\n\
	TE >= 60ms\n\
	TS >= 60ms\n\
	EC >= 1\n");
	return (1);
}

int
	ph_out_msg(t_pii *plato, char *mes, int mnum)
{
	pthread_mutex_lock(plato->died);
	if (!*plato->fin)
	{
		if (mnum == 0)
			printf(YELLOW"%lld %d %s\n"RESET,
				get_time(), plato->id, mes);
		else if (mnum == 1)
			printf(GREEN"%lld %d %s\n"RESET,
				get_time(), plato->id, mes);
		else if (mnum == 2)
			printf(MAGENTA"%lld %d %s\n"RESET,
				get_time(), plato->id, mes);
		else if (mnum == 3)
			printf(CYAN"%lld %d %s\n"RESET,
				get_time(), plato->id, mes);
		else if (mnum == 4)
			printf(RED"%lld %d %s\n"RESET,
				get_time(), plato->id, mes);
	}
	pthread_mutex_unlock(plato->died);
	return (0);
}

void
	print_plato(t_pii *plato)
{
	printf("===plato_status====================\n");
	printf("id: %d\n", plato->id);
	printf("number_of_philosophers: %d\n", plato->number_of_philosophers);
	printf("time_to_die: %d\n", plato->time_to_die);
	printf("time_to_eat: %d\n", plato->time_to_eat);
	printf("time_to_sleep: %d\n", plato->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n",
		plato->number_of_times_each_philosopher_must_eat);
	printf("is_must_eat: %d\n", plato->is_must_eat);
	printf("eat_cnt: %d\n", plato->eat_cnt);
	printf("meal_fin: %d\n", *plato->meal_fin);
	printf("fin: %d\n", *plato->fin);
	printf("lasteat: %lld\n", plato->lasteat);
	printf("start: %lld\n", plato->start);
	printf("fork: %p\n", plato->fork);
	printf("fork_id: %d\n", *plato->fork);
	printf("\n\n");
}

void
	print_ph(t_philo *ph)
{
	int	i;

	printf("===ph_status====================\n");
	printf("number_of_philosophers: %d\n", ph->number_of_philosophers);
	printf("time_to_die: %d\n", ph->time_to_die);
	printf("time_to_eat: %d\n", ph->time_to_eat);
	printf("time_to_sleep: %d\n", ph->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n",
		ph->number_of_times_each_philosopher_must_eat);
	printf("is_must_eat: %d\n", ph->is_must_eat);
	printf("meal_fin: %d\n", ph->meal_fin);
	printf("fin: %d\n", ph->fin);
	i = -1;
	while (++i < ph->number_of_philosophers)
		printf("silver[%d]: %p\n", i, &ph->silver[i]);
	i = -1;
	while (++i < ph->number_of_philosophers)
		printf("silver_id[%d]: %d\n", i, ph->silver[i]);
	printf("\n\n");
}
