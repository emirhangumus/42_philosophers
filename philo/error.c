/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:08:19 by egumus            #+#    #+#             */
/*   Updated: 2024/02/13 06:33:03 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *message, t_state *state)
{
	if (state && ft_strncmp(message, "[R", 2) != 0)
		free_state(state);
	printf("[ERROR]: %s\n", message);
	return (1);
}
