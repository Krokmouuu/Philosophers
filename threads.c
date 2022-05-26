/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:54:03 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/26 19:11:46 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*deathchecker(void *args)
{
	t_philo *philo;

    philo = (t_philo *)args;
    while (1)
    {
        pthread_mutex_lock(&philo->last_meal_m);
        pthread_mutex_lock(&philo->time_die_m);
        pthread_mutex_lock(&philo->parse->actual_time_m);
        // printf("philo[%d] last meal = %ld time_die = %d\n", philo->id ,philo->last_meal, philo->parse->time_die);
        if ( philo->parse->time_die + philo->last_meal <= actual_time())
        {
            pthread_mutex_lock(&philo->parse->print);
            print(actual_time() - philo->parse->time, philo->id, DIED);
            pthread_mutex_unlock(&philo->parse->finish);
            break ;
        }
         pthread_mutex_unlock(&philo->last_meal_m);
        pthread_mutex_unlock(&philo->time_die_m);
        pthread_mutex_unlock(&philo->parse->actual_time_m);
    }
    return (NULL);
}

void	*routine(void *args)
{
    t_philo *philo;

    philo = (t_philo *)args;
    if (philo->id % 2 == 0)
        ft_usleep(philo->parse->time_eat / 10);
    while (1)
    {
        activity(philo);
        think(philo);
        // if (++philo->nb_eat == philo->parse->nb_eat)
        // {
        //     if (++philo->parse->philo_eat == philo->parse->nb_philo)
        //     {
        //         pthread_mutex_lock(&philo->print);
        //         printf("%d philosophers ate %d times(s)\n",
        //             philo->parse->nb_philo, philo->parse->nb_eat);
        //         pthread_mutex_unlock(&philo->print);
        //         pthread_mutex_unlock(&philo->parse->finish);
        //     }
        // }
    }
    return (NULL);
}

int	createphilo(t_all *philo)
{
    int i;

    i = -1;
    while (++i < philo->parse.nb_philo)
    {
        philo->phil[i].parse = &philo->parse;
        if (pthread_create(&philo->phil[i].philo, NULL, routine, &philo->phil[i]))
            return (0);
        pthread_create(&philo->phil[i].philo, NULL, deathchecker, &philo->phil[i]);
    }
    i = -1;
    while (++i < philo->parse.nb_philo)
        pthread_detach(philo->phil[i].philo);
    return (1);
}