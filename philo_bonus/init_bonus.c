/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:55:39 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/06 01:03:08 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->infos.n_ph)
	{
		philo->process[i].id = i;
		philo->process[i].philo = philo;
		i++;
	}
}
