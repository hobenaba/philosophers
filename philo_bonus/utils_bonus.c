/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:00:29 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/06 01:03:37 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	print(t_process *process, char *str, int base)
{
	sem_wait(process -> philo -> sem);
	printf("%ld ms the philosopher nu : %d %s\n", the_right_time(process),
		process -> id + 1, str);
	if (base != 1)
		sem_post(process -> philo -> sem);
}

unsigned long	the_right_time(t_process *process)
{
	gettimeofday(&(process -> end), NULL);
	return ((process -> end.tv_sec * 1000
			+ process -> end.tv_usec / 1000)
		- (process -> philo ->start.tv_sec * 1000
			+ process -> philo ->start.tv_usec / 1000));
}
