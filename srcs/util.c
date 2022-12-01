/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:58:26 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/10 20:18:03 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	all_free(t_philo *ph)
{
	free(ph->silver);
	free(ph->men);
	free(ph->fork);
	return (0);
}

long long
	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

static int
	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int
	ft_atoi(char *str)
{
	long long	res;
	int			sign;
	int			num;

	if (!str)
		return (0);
	while (*str == ' ' || (11 <= *str && *str <= 15))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
	{
		num = (*str++ - '0');
		res = res * 10 + sign * num;
		if (res < INT_MIN || INT_MAX < res)
			return (-1);
	}
	return (res);
}
