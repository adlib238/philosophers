/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:19:05 by kfumiya           #+#    #+#             */
/*   Updated: 2021/11/10 21:01:59 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <string.h>

# define INT_MAX		INT32_MAX
# define INT_MIN		INT32_MIN
# define MSG_FORK		"has taken a fork"
# define MSG_EAT		"is eating"
# define MSG_THINK		"is thinking"
# define MSG_SLEEP		"is sleeping"
# define MSG_DIED		"is died"
# define ERR_MALLOC		"malloc failed"
# define ERR_MUTEX		"mutex_init failed"
# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"

enum	e_mnum
{
	FORK,
	EAT,
	THINK,
	SLEEP,
	DIED,
	INV
};

typedef struct s_pii
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	bool			is_must_eat;
	int				id;
	int				eat_cnt;
	int				*meal_fin;
	bool			*fin;
	long long		lasteat;
	long long		start;
	int				*fork;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*died;
	pthread_t		thread;
}	t_pii;

typedef struct s_philo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	bool			is_must_eat;
	t_pii			*men;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	died;
	bool			fin;
	pthread_t		observer;
	int				meal_fin;
	int				*silver;
}	t_philo;
int			all_free(t_philo *ph);
int			ph_init_pram(int ac, char *av[], t_philo *ph);
void		men_def(t_pii *plato);
int			men_init_set(t_philo *ph);
int			check_pram(t_philo *ph);
int			ph_solo(t_philo *ph);
int			print_usage(void);
int			ft_atoi(char *str);
int			error_msg(char *msg);
long long	get_time(void);
void		ph_loop(t_philo *ph);
void		*ph_task(void *p);
int			ph_out_msg(t_pii *plato, char *mes, int mnum);
int			ph_eat(t_pii *plato);
void		ph_wait(t_pii *plato, int time);
int			ph_take_fork(t_pii *plato);
void		*ph_observer(void *p);
int			ph_init_fork(t_philo *ph);
int			ph_init_eat(t_philo *ph);
void		ph_mutex_destroy(t_philo *ph);
void		print_plato(t_pii *plato);
void		print_ph(t_philo *ph);
void		ph_first_wait(t_pii *plato);
void		ph_sleep_think(t_pii *plato);
#endif
