/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startphilo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:16:18 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/26 19:07:26 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void 	init(t_all *philo)
{
	int	i;

	i = -1;
	pthread_mutex_init(&philo->phil->time_eat, NULL);
	pthread_mutex_init(&philo->phil->last_meal_m, NULL);
	pthread_mutex_init(&philo->phil->time_die_m, NULL);
	while (++i < philo->parse.nb_philo)
	{
		philo->phil[i].id = i + 1;
		philo->phil[i].nb_eat = 0;
		philo->phil[i].right = NULL;
		philo->phil[i].last_meal = actual_time();
		pthread_mutex_init(&philo->phil[i].left, NULL);
		if (i == philo->parse.nb_philo - 1)
			philo->phil[i].right = &philo->phil[0].left;
		else
			philo->phil[i].right = &philo->phil[i + 1].left;
	}
	return ;
}
