/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:47:31 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/26 19:17:50 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	think(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->parse->print);
// 	print(actual_time() - philo->parse->time, philo->id, SLEEP);
// 	pthread_mutex_unlock(&philo->parse->print);
// 	ft_usleep(philo->parse->time_sleep);
// 	pthread_mutex_lock(&philo->parse->print);
// 	print(actual_time() - philo->parse->time, philo->id, THINK);
// 	pthread_mutex_unlock(&philo->parse->print);
// }

// void	activity(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->left);
// 	pthread_mutex_lock(&philo->parse->print);
// 	print(actual_time() - philo->parse->time, philo->id, FORK);
// 	pthread_mutex_unlock(&philo->parse->print);
// 	if (!philo->right)
// 	{
// 		pthread_mutex_lock(&philo->time_die_m);
// 		ft_usleep(philo->parse->time_die * 2);
// 		pthread_mutex_unlock(&philo->time_die_m);
// 		return ;
// 	}
// 	pthread_mutex_lock(philo->right);
// 	pthread_mutex_lock(&philo->parse->print);
// 	print(actual_time() - philo->parse->time, philo->id, FORK);
// 	pthread_mutex_unlock(&philo->parse->print);
// 	pthread_mutex_lock(&philo->parse->print);
// 	print(actual_time() - philo->parse->time, philo->id, EAT);
// 	pthread_mutex_unlock(&philo->parse->print);
// 	pthread_mutex_lock(&philo->last_meal_m);
// 	pthread_mutex_lock(&philo->parse->actual_time_m);
// 	philo->last_meal = actual_time();
// 	pthread_mutex_unlock(&philo->parse->actual_time_m);
// 	pthread_mutex_unlock(&philo->last_meal_m);
// 	ft_usleep(philo->parse->time_eat);
// 	pthread_mutex_unlock(philo->right);
// 	pthread_mutex_unlock(&philo->left);
// 	think(philo);
// }

void think(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(philo->right);
	print(actual_time() - philo->parse->time, philo->id, SLEEP);
	ft_usleep(philo->parse->time_sleep);
	print(actual_time() - philo->parse->time, philo->id, THINK);
}

void activity(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	print(actual_time() - philo->parse->time, philo->id, FORK);
	pthread_mutex_lock(philo->right);
	print(actual_time() - philo->parse->time, philo->id, FORK);
	print(actual_time() - philo->parse->time, philo->id, EAT);
	pthread_mutex_lock(&philo->parse->actual_time_m);
	pthread_mutex_lock(&philo->last_meal_m);
	philo->last_meal = actual_time();
	pthread_mutex_unlock(&philo->last_meal_m);
	pthread_mutex_unlock(&philo->parse->actual_time_m);
	ft_usleep(philo->parse->time_eat);
}

