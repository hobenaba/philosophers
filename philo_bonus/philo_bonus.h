/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:33:18 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/06 01:07:30 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <signal.h>

// this struct will take infos that will help me in my code as a whole
typedef struct t_infos
{
	int	n_ph;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_meals;
}	t_infos;

typedef struct t_process
{
	struct timeval	end;
	struct t_philo	*philo;
	int				id;
	size_t			l_meal;
}	t_process;
// this struct will be the mother of all other structs and general infos
typedef struct t_philo
{
	int				id;
	int				enough;
	int				times;
	t_infos			infos;
	struct timeval	start;
	t_process		*process;
	sem_t			*forks;
	pthread_t		death;
	sem_t			*sem;
	sem_t			*sem2;
}	t_philo;

// utils that will help into building my program
void			print(t_process *process, char *str, int base);
void			mysleep(size_t microseconds);
unsigned long	the_right_time(t_process *process);
int				check_dead(t_philo *philo);
// to initialize
void			init_forks(t_process *process);
void			init_locks(t_process *process);
void			init_process(t_philo *philo);

//my representative actions
void			*check_if_to_die(void *arg);
int				picking_the_fork(t_process *process);
int				check_if_to_eat(t_process *process);
void			others(t_process *process);

//to parse my arguments
void			ft_store_data(int ac, char **av, t_philo *philo);
int				ft_check_args(char **av);
int				ft_atoi(const char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(const char *s);

#endif