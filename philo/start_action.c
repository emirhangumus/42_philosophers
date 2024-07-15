/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:35:57 by egumus            #+#    #+#             */
/*   Updated: 2024/02/13 07:00:50 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_someone_died(t_state *s)
{
	int		i;
	long	t;

	pthread_mutex_lock(s->death_mutex);
	i = 0;
	while (i < s->number_of_philo)
	{
		t = time_now();
		if (t - s->philos[i]->last_eat > s->philos[i]->state->time_to_die)
		{
			s->is_someone_died = 1;
			printf("%ld %d %s\n", t - s->start_time,
				s->philos[i]->id, ACTION_DIED);
			return (pthread_mutex_unlock(s->death_mutex), 1);
		}
		i++;
	}
	pthread_mutex_unlock(s->death_mutex);
	usleep(250);
	return (0);
}

int	is_all_ate(t_state *s)
{
	int	i;

	i = -1;
	if (s->nb_philo_must_eat == -1)
		return (0);
	pthread_mutex_lock(s->death_mutex);
	while (++i < s->number_of_philo)
	{
		if (!s->philos[i]->am_i_full)
		{
			pthread_mutex_unlock(s->death_mutex);
			return (0);
		}
	}
	pthread_mutex_unlock(s->death_mutex);
	return (1);
}

static void	ft_check_philos(t_state *s)
{
	while (1)
	{
		if (is_someone_died(s) || is_all_ate(s))
			break ;
	}
}

int	start_action(t_state *s)
{
	int	i;

	i = -1;
	s->start_time = time_now();
	while (++i < s->number_of_philo)
	{
		s->philos[i]->last_eat = s->start_time;
		if (pthread_create(&s->philos[i]->thread, NULL,
				&philo_routine, s->philos[i]))
			return (ft_error("Thread creation failed!", s));
	}
	i = -1;
	ft_check_philos(s);
	while (++i < s->number_of_philo)
	{
		if (pthread_join(s->philos[i]->thread, NULL))
			return (ft_error("Thread join failed!", s));
	}
	return (0);
}
