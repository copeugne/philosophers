/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:06:57 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/25 12:02:58 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*routine_philo(void *thread_arg)
{
	t_philo *philo;
	t_data	*data;
	
	philo = (t_philo *)thread_arg;
	data = (t_data *)philo->data;

	// printf(BLUE"data->philo[10].is_full : %d\n"NORMAL, data->philo[10].is_full);
	while (is_end(data) == 0)
	{
		sub_eat(data, philo);
		pthread_mutex_lock(&data->mutex_write);
		pthread_mutex_unlock(&data->mutex_write);
		sub_sleep(data, philo);
		printf(YELLOW"ft_time() - data->philo[philo->index].last_meal : %ld\n"NORMAL, ft_time() - data->philo[philo->index].last_meal);
		ft_display_message(data, philo->index, "is thinking");
		usleep(1000);
	}
	// printf("EXIT THREAD %d\n", philo->index);
	return (0);
}

