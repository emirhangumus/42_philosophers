/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 01:01:55 by egumus            #+#    #+#             */
/*   Updated: 2024/02/13 06:49:21 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status_eat(t_philo *philo, long t)
{
	philo->last_eat = t;
	philo->eat_count++;
	if (philo->eat_count == philo->state->nb_philo_must_eat)
		philo->am_i_full = 1;
}

int	print_status(t_philo *philo, char *action)
{
	long	t;

	pthread_mutex_lock(philo->state->death_mutex);
	if (philo->state->is_someone_died || philo->am_i_full)
		return (pthread_mutex_unlock(philo->state->death_mutex), 1);
	if (!philo->state->is_someone_died && !philo->am_i_full)
	{
		t = time_now();
		printf("%ld %d %s\n", t - philo->state->start_time,
			philo->id, action);
		if (ft_strcmp(action, ACTION_EATING) == 0)
			ft_print_status_eat(philo, t);
	}
	pthread_mutex_unlock(philo->state->death_mutex);
	return (0);
}
