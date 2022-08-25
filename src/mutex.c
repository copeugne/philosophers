/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:18:38 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/24 13:10:45 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// TODO: Add mutex/thread protections everywhere
// ? My fork is the left fork

int	fork_locker(t_data *data, t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		if (philo->index == 0)
			pthread_mutex_lock(&data->mutex_fork[data->args.nb_philo - 1]);
		else
			pthread_mutex_lock(&data->mutex_fork[philo->index - 1]);
		ft_display_message(data, philo->index, "has taken a fork");
		pthread_mutex_lock(&data->mutex_fork[philo->index]);
		ft_display_message(data, philo->index, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&data->mutex_fork[philo->index]);
		ft_display_message(data, philo->index, "has taken a fork");	
		if (philo->index == 0)
			pthread_mutex_lock(&data->mutex_fork[data->args.nb_philo - 1]);
		else
			pthread_mutex_lock(&data->mutex_fork[philo->index - 1]);
		ft_display_message(data, philo->index, "has taken a fork");
	}
	return (0);
}

int	fork_unlocker(t_data *data, t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		if (philo->index == 0)
			pthread_mutex_unlock(&data->mutex_fork[data->args.nb_philo - 1]);
		else
			pthread_mutex_unlock(&data->mutex_fork[philo->index - 1]);
		ft_display_message(data, philo->index, "has taken a fork");
		pthread_mutex_unlock(&data->mutex_fork[philo->index]);
		ft_display_message(data, philo->index, "has taken a fork");
	}
	else
	{
		pthread_mutex_unlock(&data->mutex_fork[philo->index]);
		ft_display_message(data, philo->index, "has taken a fork");	
		if (philo->index == 0)
			pthread_mutex_unlock(&data->mutex_fork[data->args.nb_philo - 1]);
		else
			pthread_mutex_unlock(&data->mutex_fork[philo->index - 1]);
		ft_display_message(data, philo->index, "has taken a fork");
	}
	return (0);
}

int mutex_destroyer(t_data *data)
{
	int i;
	
	i = 0;
	pthread_mutex_lock(&data->mutex_write);
	printf(RED"Mutex destroyer called\n"NORMAL);
	pthread_mutex_unlock(&data->mutex_write);
	if (pthread_mutex_destroy(&data->mutex_death) != 0)
		error(71, "Error mutex_destroyer : Issue in pthread mutex destroy death");
	if (pthread_mutex_destroy(&data->mutex_write) != 0)
		error(72, "Error mutex_destroyer : Issue in pthread mutex destroy write");
	if (pthread_mutex_destroy(&data->mutex_nbtte) != 0)
		error(73, "Error mutex_destroyer : Issue in pthread mutex destroy nbtte");
	while (i < data->args.nb_philo)
	{
		if (pthread_mutex_destroy(&data->mutex_fork[i]) != 0)
			error(74, "Error mutex_destroyer : Issue in pthread mutex destroy fork");
		i++;
	}
	return (0);
}
