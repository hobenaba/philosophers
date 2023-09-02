/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:44 by hobenaba          #+#    #+#             */
/*   Updated: 2023/04/13 17:38:19 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	my_countnbr(int n)
{
	int	j;

	j = 0;
	if (n <= 0)
		j++;
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	int				signe;
	unsigned long	res;

	signe = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (signe * res);
}

int	ft_check_args(char **av)
{
	int	j;
	int	i;

	j = 1;
	while (av[j])
	{
		i = -1;
		if (ft_atoi(av[j]) == 0 || av[j][0] == '-'
			|| ft_strlen(av[j]) != my_countnbr(ft_atoi(av[j])))
		{
			while (av[j][++i])
			{	
				if (av[j][i + 1] != '\0' && av[j][0] == '+')
					i++;
				if (!(av[j][i] >= '0' && av[j][i] <= '9'))
					return (printf("error\n"), 1);
			}
		}
		j++;
	}
	if (ft_atoi(av[1]) == 0)
		return (1);
	return (0);
}

void	ft_store_data(int ac, char **av, t_philo *philo)
{
	int	i;

	i = 0;
	if (ac == 5)
		philo ->infos.n_meals = -1;
	while (i < ac - 1)
	{
		if (i == 0)
			philo -> infos.n_ph = ft_atoi(av[i + 1]);
		else if (i == 1)
			philo -> infos.t_die = ft_atoi(av[i + 1]);
		else if (i == 2)
			philo -> infos.t_eat = ft_atoi(av[i + 1]);
		else if (i == 3)
			philo -> infos.t_sleep = ft_atoi(av[i + 1]);
		else
			philo -> infos.n_meals = ft_atoi(av[i + 1]);
		i++;
	}
}
