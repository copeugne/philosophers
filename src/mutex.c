/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:18:38 by copeugne          #+#    #+#             */
/*   Updated: 2022/11/22 19:06:19 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// TODO: Add mutex/thread protections everywhere
// ? My fork is the left fork

/**
 * It locks the forks in a particular way to prevent deadlocks
 * 
 * @param data a pointer to the data structure
 * @param philo a pointer to the current philosopher
 * 
 * @return 0.
 */
int	fork_locker(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->mutex_fork[philo->l_fork]);
	ft_display_message(data, philo->index, "has taken a fork");
	pthread_mutex_lock(&data->mutex_fork[philo->r_fork]);
	ft_display_message(data, philo->index, "has taken a fork");
	return (0);
}

/**
 * It unlocks the forks in the same order they were locked
 * 
 * @param data a pointer to the data structure
 * @param philo a pointer to the current philosopher
 * 
 * @return 0.
 */
int	fork_unlocker(t_data *data, t_philo *philo)
{
	pthread_mutex_unlock(&data->mutex_fork[philo->l_fork]);
	pthread_mutex_unlock(&data->mutex_fork[philo->r_fork]);
	return (0);
}

/**
 * It destroys all the mutexes
 * 
 * @param data a pointer to the data structure
 * 
 * @return 0.
 */
int	mutex_destroyer(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->mutex_write);
	pthread_mutex_unlock(&data->mutex_write);
	if (pthread_mutex_destroy(&data->mutex_death) != 0)
		error(71, "Error mutex_destroyer:Issue in pthread mutex destroy death");
	if (pthread_mutex_destroy(&data->mutex_write) != 0)
		error(72, "Error mutex_destroyer:Issue in pthread mutex destroy write");
	if (pthread_mutex_destroy(&data->mutex_nbtte) != 0)
		error(73, "Error mutex_destroyer:Issue in pthread mutex destroy nbtte");
	while (i < data->args.nb_philo)
	{
		if (pthread_mutex_destroy(&data->mutex_fork[i]) != 0)
			error(74, "Error mutex_destroy:Issue in pthread mutex destroy frk");
		i++;
	}
	return (0);
}
