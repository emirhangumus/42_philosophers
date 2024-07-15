/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:54:50 by egumus            #+#    #+#             */
/*   Updated: 2024/02/13 06:33:34 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_state *state)
{
	int	i;

	state->philos = malloc(sizeof(t_philo *) * state->number_of_philo);
	if (!state->philos)
		return (1);
	i = 0;
	while (i < state->number_of_philo)
	{
		state->philos[i] = malloc(sizeof(t_philo));
		if (!state->philos[i])
			return (1);
		state->philos[i]->id = i + 1;
		state->philos[i]->state = state;
		state->philos[i]->last_eat = 0;
		state->philos[i]->eat_count = 0;
		state->philos[i]->am_i_full = 0;
		state->philos[i]->left_fork = state->forks[i];
		state->philos[i]->right_fork = state->forks[(i + 1)
			% state->number_of_philo];
		i++;
	}
	return (0);
}

int	init_mutexes(t_state *state)
{
	int	i;

	i = 0;
	state->forks = malloc(sizeof(pthread_mutex_t *) * state->number_of_philo);
	if (!state->forks)
		return (1);
	while (i < state->number_of_philo)
	{
		state->forks[i] = malloc(sizeof(pthread_mutex_t));
		if (!state->forks[i])
			return (1);
		i++;
	}
	i = -1;
	while (++i < state->number_of_philo)
	{
		if (pthread_mutex_init(state->forks[i], NULL))
			return (1);
	}
	state->death_mutex = malloc(sizeof(pthread_mutex_t));
	if (!state->death_mutex)
		return (1);
	if (pthread_mutex_init(state->death_mutex, NULL))
		return (1);
	return (0);
}

int	init_state(t_state *state)
{
	if (init_mutexes(state))
		return (ft_error("Mutex init failed!", state));
	if (init_philos(state))
		return (ft_error("Malloc failed!", state));
	return (0);
}
