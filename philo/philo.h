/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:46:39 by egumus            #+#    #+#             */
/*   Updated: 2024/02/13 06:49:42 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> 
# include <stdio.h> 
# include <stdlib.h> 
# include <string.h> 
# include <unistd.h>
# include <sys/time.h>

# define ACTION_TAKE_FORK "has taken a fork"
# define ACTION_EATING "is eating"
# define ACTION_SLEEPING "is sleeping"
# define ACTION_THINKING "is thinking"
# define ACTION_DIED "died"

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				am_i_full;
	long int		last_eat;
	struct s_state	*state;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_state
{
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				nb_philo_must_eat;
	int				number_of_philo;
	int				is_someone_died;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	**forks;
	t_philo			**philos;
	long int		start_time;
}	t_state;

long int	time_now(void);
int			ft_parse_args(t_state *state, int argc, char **argv);
int			is_all_digit(char *str);
int			ft_atoi(const char *str);
int			free_state(t_state *state);
int			ft_error(char *message, t_state *state);
int			init_state(t_state *state);
int			start_action(t_state *s);
void		*philo_routine(void *philo);
int			print_status(t_philo *philo, char *action);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_usleep(long time);

#endif