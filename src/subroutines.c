/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:50:10 by copeugne          #+#    #+#             */
/*   Updated: 2022/11/22 19:07:03 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// ! Toujours encercler l'acces/la modification des donnees partagees
// ! par des mutex lock et unlock

/**
 * It displays a message, then sleeps for the time to sleep
 * 
 * @param data a pointer to the data structure
 * @param philo a pointer to the philosopher
 */
void	sub_sleep(t_data *data, t_philo *philo)
{
	ft_display_message(data, philo->index, "is sleeping");
	ft_usleep(data, data->args.ttsleep);
}

/**
 * It locks the forks, displays a message,
 * increments the number of meals, sets the last meal time,
 * unlocks the forks, and sleeps for the time to eat
 * 
 * @param data a pointer to the data structure
 * @param philo the philosopher
 */
void	sub_eat(t_data *data, t_philo *philo)
{
	fork_locker(data, philo);
	ft_display_message(data, philo->index, "is eating");
	pthread_mutex_lock(&data->mutex_last_meal);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&data->mutex_last_meal);
	ft_usleep(data, data->args.tteat);
	pthread_mutex_lock(&data->mutex_nbtte);
	if (data->args.nb_tteat != -1 && philo->nb_meals < data->args.nb_tteat)
		philo->nb_meals++;
	pthread_mutex_unlock(&data->mutex_nbtte);
	fork_unlocker(data, philo);
}
