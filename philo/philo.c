/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:53:36 by egumus            #+#    #+#             */
/*   Updated: 2024/02/13 06:33:52 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_state	*s;

	s = malloc(sizeof(t_state));
	if (!s)
		return (ft_error("Malloc failed!", s));
	if (ft_parse_args(s, ac, av))
	{
		free(s);
		return (ft_error("Invalid arguments!", NULL));
	}
	if (init_state(s))
		return (0);
	if (start_action(s))
		return (0);
	if (free_state(s))
		return (0);
	return (0);
}
