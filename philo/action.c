/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:57:11 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/13 23:21:46 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	picking_the_fork(t_thread *thread)
{
	thread -> left = thread ->id;
	thread -> right = (thread -> id + 1) % thread -> philo->infos.n_ph;
	pthread_mutex_lock(&(thread ->philo->forks[thread -> left]));
	print(thread, "took the left fork");
	pthread_mutex_lock(&(thread ->philo->forks[thread -> right]));
	print(thread, "took the right fork");
	pthread_mutex_lock(&(thread -> philo ->locks[1]));
	thread -> l_meal = thread -> philo -> t_stamp;
	pthread_mutex_unlock(&(thread -> philo ->locks[1]));
	print(thread, "is eating");
	mysleep(thread -> philo->infos.t_eat * 1000);
	thread ->n_meals++;
	pthread_mutex_unlock(&(thread ->philo->forks[thread -> left]));
	pthread_mutex_unlock(&(thread ->philo->forks[thread -> right]));
	return (0);
}

void	others(t_thread *thread)
{
	print(thread, "is sleeping");
	mysleep (thread -> philo->infos.t_sleep * 1000);
	print(thread, "is thinking");
}

int	check_if_to_eat(t_thread *thread)
{
	pthread_mutex_lock(&(thread -> philo -> locks[2]));
	if (thread -> philo -> times
		== thread ->philo->infos.n_ph * thread -> philo-> infos.n_meals)
		return (-1);
	if (thread -> n_meals < thread ->philo-> infos.n_meals)
		thread -> philo -> times++;
	pthread_mutex_unlock(&(thread -> philo -> locks[2]));
	return (0);
}

int	check_if_to_die(t_thread *thread, t_philo *philo)
{
	pthread_mutex_lock(&(philo ->locks[1]));
	if (the_right_time(thread) > thread ->l_meal + philo ->infos.t_die)
	{
		the_right_time(thread);
		printf("%ld ms the philosopher nu : %d is dead\n",
			thread -> philo -> t_stamp, thread->id + 1);
		return (1);
	}
	pthread_mutex_unlock(&(philo ->locks[1]));
	return (0);
}
