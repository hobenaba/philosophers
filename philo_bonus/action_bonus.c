/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:57:11 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/13 22:19:00 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	picking_the_fork(t_process *process)
{
	sem_wait(process ->philo->forks);
	print(process, "took the left fork", 0);
	sem_wait(process ->philo->forks);
	print(process, "took the right fork", 0);
	print(process, "is eating", 0);
	process -> l_meal = the_right_time(process);
	mysleep(process -> philo->infos.t_eat * 1000);
	sem_post(process ->philo->forks);
	sem_post(process ->philo->forks);
	return (0);
}

void	others(t_process *process)
{
	print(process, "is sleeping", 0);
	mysleep (process -> philo->infos.t_sleep * 1000);
	print(process, "is thinking", 0);
}

void	*check_if_to_die(void *arg)
{
	t_process	*process;

	process = (t_process *)arg;
	while (1)
	{
		sem_wait(process -> philo -> sem2);
		if (the_right_time(process)
			> process ->l_meal + process -> philo ->infos.t_die)
		{
			print(process, "is dead", 1);
			exit(EXIT_FAILURE);
		}
		sem_post(process -> philo -> sem2);
	}
	return (0);
}
