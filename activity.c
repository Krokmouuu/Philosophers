/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:47:31 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/24 15:46:54 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
	print(actual_time() - philo->parse->time, philo->id, SLEEP);
	pthread_mutex_unlock(&philo->print);
	ft_usleep(philo->parse->time_sleep);
	pthread_mutex_lock(&philo->print);
	print(actual_time() - philo->parse->time, philo->id, THINK);
	pthread_mutex_unlock(&philo->print);
}

void	activity(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	pthread_mutex_lock(&philo->print);
	print(actual_time() - philo->parse->time, philo->id, FORK);
	pthread_mutex_unlock(&philo->print);
	if (!philo->right)
	{
		ft_usleep(philo->parse->time_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(&philo->print);
	print(actual_time() - philo->parse->time, philo->id, FORK);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->print);
	print(actual_time() - philo->parse->time, philo->id, EAT);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->time_eat);
	philo->last_meal = actual_time();
	pthread_mutex_unlock(&philo->time_eat);
	ft_usleep(philo->parse->time_eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(&philo->left);
	think(philo);
}
