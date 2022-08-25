/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:50:10 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/25 11:59:43 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// ! Toujours encercler l'acces/la modification des donnees partagees
// ! par des mutex lock et unlock
void	sub_sleep(t_data *data, t_philo *philo)
{
	ft_display_message(data, philo->index, "is sleeping");
	ft_usleep(data->args.ttsleep);
}

void	sub_eat(t_data *data, t_philo *philo)
{
	fork_locker(data, philo);
	ft_display_message(data, philo->index, "is eating");
	pthread_mutex_lock(&data->mutex_nbtte);
	if (data->args.nb_tteat != -1 && data->philo[philo->index].nb_meals < data->args.nb_tteat)
		data->philo[philo->index].nb_meals++;
	data->philo[philo->index].last_meal = ft_time(); 
	// printf(RED"data->philo[%d].last_meal = %ld\n"NORMAL, philo->index, data->philo[philo->index].last_meal);
	pthread_mutex_unlock(&data->mutex_nbtte);
	pthread_mutex_lock(&data->mutex_write);
	// printf(BLUE"data->philo[%d].is_full : %d\n"NORMAL, philo->index, data->philo[philo->index].is_full);
	// printf(RED"philo nb %d has eaten nb meals : %d\n"NORMAL,philo->index, data->philo[philo->index].nb_meals);
	pthread_mutex_unlock(&data->mutex_write);
	ft_usleep(data->args.tteat);
	fork_unlocker(data, philo);
}