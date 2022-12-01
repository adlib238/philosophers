/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:27:52 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/10 21:16:41 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	main(int ac, char *av[])
{
	t_philo	ph;

	if (ac != 5 && ac != 6)
		return (print_usage());
	if (ph_init_pram(ac, av, &ph))
		return (all_free(&ph));
	if (ph_init_fork(&ph))
		return (all_free(&ph));
	if (ph_init_eat(&ph))
		return (all_free(&ph));
	ph_loop(&ph);
	ph_mutex_destroy(&ph);
	all_free(&ph);
	return (0);
}
