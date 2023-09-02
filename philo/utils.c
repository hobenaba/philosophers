/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:00:29 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/05 23:50:54 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	the_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	mysleep(size_t microseconds)
{
	size_t	start;
	size_t	end;

	start = the_current_time();
	end = start + microseconds;
	while (the_current_time() < end)
		usleep (100);
}

void	print(t_thread *thread, char *str)
{
	pthread_mutex_lock(&(thread -> philo ->locks[1]));
	printf("%ld ms the philosopher nu : %d %s\n", thread -> philo -> t_stamp,
		thread -> id + 1, str);
	pthread_mutex_unlock(&(thread -> philo ->locks[1]));
}

long	the_right_time(t_thread *thread)
{
	pthread_mutex_lock(&(thread -> philo ->locks[3]));
	gettimeofday(&(thread -> end), NULL);
	thread -> philo-> t_stamp = (thread->end.tv_sec * 1000
			+ thread->end.tv_usec / 1000)
		- (thread->philo ->start.tv_sec * 1000
			+ thread->philo ->start.tv_usec / 1000);
	pthread_mutex_unlock(&(thread -> philo ->locks[3]));
	return (thread -> philo ->t_stamp);
}
