/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:33:05 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/13 18:29:36 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(t_process *process)
{
	pthread_create(&process -> philo -> death, NULL, check_if_to_die, process);
	while (1)
	{
		if (process -> philo -> times == process -> philo-> infos.n_meals)
			exit (0);
		picking_the_fork(process);
		process -> philo -> times++;
		others(process);
	}
	return (NULL);
}

int	intro(t_philo *philo, int ac, char **av)
{
	if (ft_check_args(av) == 1)
		return (1);
	ft_store_data(ac, av, philo);
	philo -> process = malloc (philo ->infos.n_ph * sizeof(t_process));
	sem_unlink("/forks");
	sem_unlink("/sem");
	sem_unlink("/sem2");
	philo -> forks = sem_open("/forks", O_CREAT, 0777, philo ->infos.n_ph);
	philo -> sem = sem_open("/sem", O_CREAT, 0777, 1);
	philo -> sem2 = sem_open("/sem2", O_CREAT, 0777, 1);
	philo->times = 0;
	init_process(philo);
	gettimeofday(&(philo ->start), NULL);
	return (0);
}

void	check(t_philo *philo, int pid)
{
	int	i;
	int	status;

	status = 0;
	i = 0;
	while (i <= philo -> infos.n_ph)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			philo -> id = 0;
			while (philo -> id < philo -> infos.n_ph)
			{
				kill(pid, SIGTERM);
				philo -> id++;
			}
			exit (0);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	pid_t	pid;

	philo = malloc(sizeof(t_philo));
	philo->id = 0;
	if (ac == 5 || ac == 6)
	{
		if (intro(philo, ac, av))
			return (0);
		while (philo -> id < philo -> infos.n_ph)
		{
			pid = fork();
			if (pid == 0)
				routine(&philo -> process[philo -> id]);
			philo -> id++;
		}
		check (philo, pid);
	}
	else
		printf("Error\n");
	return (0);
}
