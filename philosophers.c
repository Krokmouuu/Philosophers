/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:12:57 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/26 19:14:52 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing2(int argc, t_all *philo)
{
	if (philo->parse.nb_philo < 0)
	{
		printf("Missing philosophers\n");
		return (0);
	}
	if (philo->parse.time_die < 0)
	{
		printf("Death timer invalid\n");
		return (0);
	}
	if (philo->parse.time_eat < 0)
	{
		printf("Eat timer invalid\n");
		return (0);
	}
	if (philo->parse.time_sleep < 0)
	{
		printf("Sleep timer invalid\n");
		return (0);
	}
	if (argc == 6)
		if (philo->parse.nb_eat < 0)
			return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_all *philo)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i][j])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Not Digit\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	philo->parse.nb_philo = ft_atoi(argv[1]);
	philo->parse.time_die = ft_atoi(argv[2]);
	philo->parse.time_eat = ft_atoi(argv[3]);
	philo->parse.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->parse.nb_eat = ft_atoi(argv[5]);
	return (1);
}

void init_parse(t_parsing *p)
{
	pthread_mutex_init(&p->finish, NULL);
	pthread_mutex_init(&p->print, NULL);
	pthread_mutex_init(&p->actual_time_m, NULL);
	p->dead = 0;
	p->time = actual_time();
}

int	main(int argc, char **argv)
{
	t_all philo;
	t_parsing p;

	if	(argc < 5 || argc > 6)
		return (printf("Wrong args\n"));
	if	(parsing(argc, argv, &philo) == 0 || parsing2(argc, &philo) == 0)
		return (0);
	pthread_mutex_init(&philo.parse.finish, NULL);
	philo.phil = malloc(sizeof(t_philo) * philo.parse.nb_philo);
	if (!philo.phil)
		return (printf("Error\n"));
	init_parse(&p);
	init(&philo);
	createphilo(&philo);
	pthread_mutex_lock(&philo.parse.finish);
	pthread_mutex_lock(&philo.parse.finish);
}