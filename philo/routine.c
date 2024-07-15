/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:38:37 by egumus            #+#    #+#             */
/*   Updated: 2024/02/13 06:49:35 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_right(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);
	if (print_status(p, ACTION_TAKE_FORK))
		return (pthread_mutex_unlock(p->right_fork), 1);
	if (p->right_fork == p->left_fork)
		return (pthread_mutex_unlock(p->right_fork), 1);
	pthread_mutex_lock(p->left_fork);
	if (print_status(p, ACTION_TAKE_FORK))
		return (pthread_mutex_unlock(p->right_fork),
			pthread_mutex_unlock(p->left_fork), 1);
	return (0);
}

int	ft_take_left(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	if (print_status(p, ACTION_TAKE_FORK))
		return (pthread_mutex_unlock(p->left_fork), 1);
	if (p->right_fork == p->left_fork)
		return (pthread_mutex_unlock(p->left_fork), 1);
	pthread_mutex_lock(p->right_fork);
	if (print_status(p, ACTION_TAKE_FORK))
		return (pthread_mutex_unlock(p->left_fork),
			pthread_mutex_unlock(p->right_fork), 1);
	return (0);
}

int	ft_take_forks(t_philo *p)
{
	if (p->id % 2)
		return (ft_take_right(p));
	else
		return (ft_take_left(p));
}

int	ft_eat(t_philo *p)
{
	if (ft_take_forks(p))
		return (1);
	if (print_status(p, ACTION_EATING))
	{
		pthread_mutex_unlock(p->right_fork);
		pthread_mutex_unlock(p->left_fork);
		return (1);
	}
	ft_usleep(p->state->time_to_eat);
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
	return (0);
}

void	*philo_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (ft_eat(p))
			break ;
		if (print_status(p, ACTION_SLEEPING))
			break ;
		ft_usleep(p->state->time_to_sleep);
		if (print_status(p, ACTION_THINKING))
			break ;
	}
	return (NULL);
}
