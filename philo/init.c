/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:55:39 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/01 14:57:12 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo -> infos.n_ph)
	{
		pthread_mutex_init(&(philo -> forks[i]), NULL);
		i++;
	}
}

void	init_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->infos.n_ph)
	{
		philo->threads[i].id = i;
		philo->threads[i].philo = philo;
		philo->threads[i].n_meals = 0;
		philo-> threads[i].l_meal = 0;
		i++;
	}
}

void	init_locks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		pthread_mutex_init(&philo -> locks[i], NULL);
		i++;
	}
}
