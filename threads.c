/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:54:03 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/30 12:03:39 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*deathchecker(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (philo->parse->time_die + philo->last_meal <= actual_time())
		{
			pthread_mutex_lock(&philo->parse->death_m);
			philo->parse->dead = 2;
			philo->parse->deadid = philo->id;
			pthread_mutex_unlock(&philo->parse->finish);
			return (NULL);
		}	
	}
	return (NULL);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		ft_usleep(actual_time() + philo->parse->time_eat / 10);
	while (1)
	{
		activity(philo);
		think(philo);
		if (++philo->nb_eat == philo->parse->nb_eat)
		{
			if (++philo->parse->philo_eat == philo->parse->nb_philo)
			{
				pthread_mutex_lock(&philo->parse->death_m);
				philo->parse->dead = 1;
				pthread_mutex_unlock(&philo->parse->finish);
				return (NULL);
			}
		}
	}
	return (NULL);
}

int	createphilo(t_all *philo)
{
	int	i;

	i = -1;
	while (++i < philo->parse.nb_philo)
	{
		philo->phil[i].parse = &(philo->parse);
		pthread_create(&philo->phil[i].philo, NULL, routine, &philo->phil[i]);
		pthread_create(&philo->phil[i].philo, NULL,
			deathchecker, &philo->phil[i]);
	}
	i = -1;
	while (++i < philo->parse.nb_philo)
		pthread_detach(philo->phil[i].philo);
	pthread_mutex_lock(&philo->parse.finish);
	pthread_mutex_lock(&philo->parse.finish);
	return (1);
}
