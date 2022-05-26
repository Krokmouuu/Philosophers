/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startphilo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:16:18 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/26 16:24:35 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_all *philo)
{
	int	i;

	i = -1;
	pthread_mutex_init(&philo->phil->finish, NULL);
	pthread_mutex_init(&philo->phil->print, NULL);
	pthread_mutex_init(&philo->phil->time_eat, NULL);
	philo->parse.dead = 0;
	philo->parse.time = actual_time();
	while (++i < philo->parse.nb_philo)
	{
		philo->phil[i].id = i + 1;
		philo->phil[i].nb_eat = 0;
		philo->phil[i].right = NULL;
		philo->phil[i].last_meal = 0;
		pthread_mutex_init(&philo->phil[i].left, NULL);
		if (i == philo->parse.nb_philo - 1)
			philo->phil[i].right = &philo->phil[0].left;
		else
			philo->phil[i].right = &philo->phil[i + 1].left;
	}
	return ;
}

int	startphilo(t_all *philo)
{
	init(philo);
	if (createphilo(philo) == 0)
		return (0);
	return (1);
}
