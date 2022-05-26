/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:39:51 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/26 19:11:59 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <unistd.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct s_parsing
{
	int					nb_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					philo_eat;
	long int			time;
	int					dead;
	pthread_mutex_t		finish;
	pthread_mutex_t		actual_time_m;
	pthread_mutex_t		print;
}	t_parsing;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	pthread_mutex_t	*right;
	pthread_mutex_t	left;
	pthread_mutex_t	time_eat; // inutlie
	pthread_mutex_t	last_meal_m;
	pthread_mutex_t	time_die_m;
	int				nb_eat;
	long int		last_meal;
	t_parsing		*parse;
}	t_philo;

typedef struct s_all
{
	t_parsing		parse;
	t_philo			*phil;
}	t_all;

int			startphilo(t_all *philo);
int	 		createphilo(t_all *philo);
void		activity(t_philo *philo);
void		think(t_philo *philo);
void		init(t_all *philo);

//* **************** Utils ****************
int			ft_atoi(const char *str);
long int	actual_time(void);
void		ft_usleep(long int time_in_ms);
void		print(long int ms, int id, char *str);

#endif