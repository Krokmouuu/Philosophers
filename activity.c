/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:47:31 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/27 14:43:12 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(philo->right);
	print(actual_time() - philo->parse->time, philo->id, SLEEP);
	ft_usleep(philo->parse->time_sleep + actual_time());
	print(actual_time() - philo->parse->time, philo->id, THINK);
}

void	activity(t_philo *philo)
{
	if (philo->parse->nb_philo == 1)
	{
		pthread_mutex_lock(&philo->left);
		print(actual_time() - philo->parse->time, philo->id, FORK);
		ft_usleep(philo->parse->time_sleep * 2);
		return ;
	}
	pthread_mutex_lock(&philo->left);
	pthread_mutex_lock(&philo->parse->print);
	print(actual_time() - philo->parse->time, philo->id, FORK);
	pthread_mutex_lock(philo->right);
	print(actual_time() - philo->parse->time, philo->id, FORK);
	print(actual_time() - philo->parse->time, philo->id, EAT);
	pthread_mutex_lock(&philo->parse->actual_time_m);
	pthread_mutex_lock(&philo->last_meal_m);
	philo->last_meal = actual_time();
	pthread_mutex_unlock(&philo->last_meal_m);
	pthread_mutex_unlock(&philo->parse->actual_time_m);
	ft_usleep(philo->last_meal + philo->parse->time_eat);
}
