/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:50:10 by copeugne          #+#    #+#             */
/*   Updated: 2022/10/21 22:10:56 by copeugne         ###   ########.fr       */
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
	// if (data->args.nb_philo % 2 == 0)
	// {
	// 	if (ft_time() - philo->last_meal + data->args.tteat >= data->args.ttdie)
	// 	{
	// 		ft_usleep(data->args.ttdie - data->args.tteat);
	// 		ft_display_message(data, philo->index, "died");
	// 		pthread_mutex_lock(&data->is_dead);
	// 		data->is_dead = 1;
	// 		pthread_mutex_unlock(&data->is_dead);
	// 	}
	// }
	// else
	// {
	// 	if (ft_time() - philo->last_meal + data->args.tteat * 2 >= data->args.ttdie)
	// 	{
	// 		ft_usleep(data->args.ttdie - data->args.tteat);
	// 		ft_display_message(data, philo->index, "died");
	// 		pthread_mutex_lock(&data->is_dead);
	// 		data->is_dead = 1;
	// 		pthread_mutex_unlock(&data->is_dead);
	// 	}
	// }
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
	// data->philo[philo->index].nb_meals
	fork_locker(data, philo);
	ft_display_message(data, philo->index, "is eating");
		// data->philo[philo->index].nb_meals++;
	// data->philo[philo->index].last_meal = ft_time();
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
