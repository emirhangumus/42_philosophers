/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:51:36 by egumus            #+#    #+#             */
/*   Updated: 2024/02/10 10:02:20 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_forks(pthread_mutex_t **forks, int number_of_philo)
{
	int	i;

	i = -1;
	while (++i < number_of_philo)
	{
		pthread_mutex_unlock(forks[i]);
		if (pthread_mutex_destroy(forks[i]))
			return (ft_error("[R1] Mutex destroy failed!", NULL), 1);
		free(forks[i]);
	}
	free(forks);
	forks = NULL;
	return (0);
}

int	free_philos(t_philo **philos, int number_of_philo)
{
	int	i;

	i = -1;
	while (++i < number_of_philo)
	{
		if (philos[i])
			free(philos[i]);
	}
	free(philos);
	philos = NULL;
	return (0);
}

int	free_state(t_state *state)
{
	if (state->philos != NULL)
		free_philos(state->philos, state->number_of_philo);
	if (state->forks != NULL)
		free_forks(state->forks, state->number_of_philo);
	if (state->death_mutex != NULL)
	{
		pthread_mutex_unlock(state->death_mutex);
		if (pthread_mutex_destroy(state->death_mutex))
			return (ft_error("[R2] Mutex destroy failed!", state), 1);
		free(state->death_mutex);
	}
	free(state);
	return (0);
}
