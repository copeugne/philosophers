/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:47:08 by copeugne          #+#    #+#             */
/*   Updated: 2022/10/21 17:10:23 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/**
 * It checks the end conditions.
 * 
 * @param data the structure containing all the data
 * 
 * @return function is_end returns 1 if the end condition is met, 0 otherwise.
 */
int	is_end(t_data *data)
{
	if (check_death(data) || check_nb_meals(data))
		return (1);
	return (0);
}

/**
 * It joins all the philosopher threads.
 * 
 * @param data the structure containing all the data
 * 
 * @return 0.
 */
int	thread_joiner(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->mutex_write);
	pthread_mutex_unlock(&data->mutex_write);
	while (i < data->args.nb_philo)
	{
		if (pthread_join(data->philo[i].philo_thread, NULL) != 0)
			error(61, "Error thread_joiner : Issue in pthread join");
		i++;
	}
	return (0);
}
