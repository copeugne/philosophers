/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:18:23 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/25 09:27:23 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	init_datastruct(t_data *data)
{
	data->is_dead = 0;
	data->all_ate = 0;
}

int	init_philo_index(t_data *data)
{
	int		i;
	long	time;

	i = 0;
	time = ft_time();
	while (i < data->args.nb_philo)
	{
		data->philo[i].index = i;
		data->philo[i].data = (void *)data;
		data->philo[i].nb_meals = 0;
		data->philo[i].start_time = time;
		i++;
	}
	return (0);
}

int	init_philo_threads(t_data *data)
{
	int i;

	i = 0;
	init_philo_index(data);
	while(i < data->args.nb_philo)
	{
		// TODO: Prevent memory leaks, patch/fix them
		if (pthread_create(&data->philo[i].philo_thread, NULL, &routine_philo,
			&data->philo[i]) != 0)
			error(41, "Error init_philo_threads : Issue in pthread creation");
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int i;

	i = 0;
	if (pthread_mutex_init(&data->mutex_death, NULL) != 0)
		error(51, "Error init_mutex : Issue in pthread mutex init death");
	if (pthread_mutex_init(&data->mutex_write, NULL) != 0)
		error(52, "Error init_mutex : Issue in pthread mutex init write");
	if (pthread_mutex_init(&data->mutex_nbtte, NULL) != 0)
		error(53, "Error init_mutex : Issue in pthread mutex init nbtte");
	while (i < data->args.nb_philo)
	{
		if (pthread_mutex_init(&data->mutex_fork[i], NULL) != 0)
		error(54, "Error init_mutex : Issue in pthread mutex init fork");
		i++;
	}
	return (0);
}