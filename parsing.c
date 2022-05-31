/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:07:39 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/31 15:56:50 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parseattrib(t_all *philo, int argc, char **argv)
{
	philo->parse.nb_philo = ft_atoi(argv[1]);
	philo->parse.time_die = ft_atoi(argv[2]);
	philo->parse.time_eat = ft_atoi(argv[3]);
	philo->parse.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->parse.nb_eat = ft_atoi(argv[5]);
}

int	parsing2(int argc, t_all *philo)
{
	if (philo->parse.nb_philo <= 0)
	{
		printf("Missing philosophers\n");
		return (0);
	}
	if (philo->parse.time_die <= 0)
	{
		printf("Death timer invalid\n");
		return (0);
	}
	if (philo->parse.time_eat <= 0)
	{
		printf("Eat timer invalid\n");
		return (0);
	}
	if (philo->parse.time_sleep <= 0)
	{
		printf("Sleep timer invalid\n");
		return (0);
	}
	if (argc == 6)
		if (philo->parse.nb_eat <= 0)
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
	parseattrib(philo, argc, argv);
	return (1);
}
