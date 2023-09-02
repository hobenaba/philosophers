/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:33:05 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/13 22:30:37 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *)arg;
	while (1)
	{
		if (check_if_to_eat(thread) == -1)
		{
			pthread_mutex_lock(&(thread -> philo -> locks[0]));
			thread -> philo -> enough = 1;
			pthread_mutex_unlock(&(thread -> philo -> locks[0]));
			return (NULL);
		}
		picking_the_fork(thread);
		others(thread);
	}
	return (NULL);
}

int	intro(t_philo *philo, int ac, char **av)
{
	if (ft_check_args(av) == 1)
		return (1);
	ft_store_data(ac, av, philo);
	philo->threads = malloc (philo ->infos.n_ph * sizeof(t_thread));
	philo->forks = malloc (philo ->infos.n_ph * sizeof(pthread_mutex_t));
	philo->locks = malloc (4 * sizeof(pthread_mutex_t));
	philo->enough = 0;
	philo->times = 0;
	philo->t_stamp = 0;
	init_forks(philo);
	init_thread(philo);
	init_locks(philo);
	gettimeofday(&(philo ->start), NULL);
	return (0);
}

int	keep_in_check(t_philo *philo)
{	
	while (1)
	{
		if (philo -> id == philo -> infos.n_ph)
			philo -> id = 0;
		pthread_mutex_lock(&(philo -> locks[0]));
		if (check_if_to_die(&(philo -> threads[philo -> id]), philo)
			|| philo -> enough == 1)
			return (1);
		pthread_mutex_unlock(&(philo -> locks[0]));
		philo ->id++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->id = 0;
	if (ac == 5 || ac == 6)
	{
		if (intro(philo, ac, av))
			return (0);
		while (philo->id < philo->infos.n_ph)
		{
			pthread_create(&(philo->threads[philo->id].thread),
				NULL, routine, &(philo->threads[philo->id]));
			pthread_detach(philo->threads[philo->id].thread);
			usleep (100);
			philo->id++;
		}
		philo ->id = 0;
		if (keep_in_check(philo))
			return (0);
	}
	else
		printf("Error\n");
	return (0);
}
