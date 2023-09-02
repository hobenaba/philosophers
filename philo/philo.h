/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:33:18 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/13 22:30:48 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

// this struct will take infos that will help me in my code as a whole
typedef struct t_infos
{
	int	n_ph;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_meals;
}	t_infos;

// the struct that characterize each philo at time
typedef struct t_thread
{
	int				id;
	int				left;
	int				right;
	long			l_meal;
	int				n_meals;
	struct timeval	end;
	pthread_t		thread;
	struct t_philo	*philo;
}	t_thread;
// this struct will be the mother of all other structs and general infos
typedef struct t_philo
{
	int				id;
	int				enough;
	int				times;
	long			t_stamp;
	t_infos			infos;
	t_thread		*threads;
	struct timeval	start;
	pthread_mutex_t	*locks;
	pthread_mutex_t	*forks;
}	t_philo;

// utils that will help into building my program
void	print(t_thread *thread, char *str);
void	mysleep(size_t microseconds);
long	the_right_time(t_thread *thread);
// to initialize
void	init_forks(t_philo *philo);
void	init_locks(t_philo *philo);
void	init_thread(t_philo *philo);

//my representative actions
int		check_if_to_die(t_thread *thread, t_philo *philo);
int		picking_the_fork(t_thread *thread);
int		check_if_to_eat(t_thread *thread);
void	others(t_thread *thread);

//to parse my arguments
void	ft_store_data(int ac, char **av, t_philo *philo);
int		ft_check_args(char **av);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *s);

#endif