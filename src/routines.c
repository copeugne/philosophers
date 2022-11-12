/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:06:57 by copeugne          #+#    #+#             */
/*   Updated: 2022/10/21 22:28:52 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/**
 * It's the routine a philosopher must follow
 * 
 * @param thread_arg the argument passed to the thread when it was created.
 * 
 * @return 0.
 */
void	*routine_philo(void *thread_arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)thread_arg;
	data = (t_data *)philo->data;
	if (data->args.nb_philo == 1 || data->args.ttdie == 0)
	{
		ft_display_message(data, philo->index, "has taken a fork");
		ft_usleep(data, data->args.ttdie);
		ft_display_message(data, philo->index, "died");
		// pthread_mutex_lock(&data->mutex_death);
		// data->is_dead = 1;
		// pthread_mutex_unlock(&data->mutex_death);
		return (0);
	}
	if (philo->index % 2 == 0)
		usleep(1000);
	while (!is_end(data))
	{
		sub_eat(data, philo);
		pthread_mutex_lock(&data->mutex_write);
		pthread_mutex_unlock(&data->mutex_write);
		sub_sleep(data, philo);
		ft_display_message(data, philo->index, "is thinking");
		// usleep(1000);
	}
	return (0);
}
