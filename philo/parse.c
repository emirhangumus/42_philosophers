/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:12:25 by egumus            #+#    #+#             */
/*   Updated: 2024/02/13 06:44:10 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parse_args(t_state *state, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (!is_all_digit(argv[1]) || !is_all_digit(argv[2])
		|| !is_all_digit(argv[3])
		|| !is_all_digit(argv[4]) || (argc == 6 && !is_all_digit(argv[5])))
		return (1);
	state->number_of_philo = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		state->nb_philo_must_eat = ft_atoi(argv[5]);
	else
		state->nb_philo_must_eat = -1;
	state->is_someone_died = 0;
	return (0);
}
