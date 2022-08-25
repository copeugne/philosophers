/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:26:08 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/25 12:18:16 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	check_nbmeals_philo(t_data *data)
{
	int c;
	int	i;

	c = 0;
	i = 0;
	while (i < data->args.nb_philo - 1)
	{
		if (data->philo[i].nb_meals >= data->args.nb_tteat)
			c++;
		i++;
	}
	// pthread_mutex_lock(&data->mutex_write);
	// printf(YELLOW"Nb philo full : %d\n"NORMAL, c);
	// printf(BLUE"data->args.nb_philo - 1: %d\n"NORMAL, data->args.nb_philo - 1);
	// printf(BLUE"data->args.nb_tteat : %d\n"NORMAL, data->args.nb_tteat);
	// pthread_mutex_unlock(&data->mutex_write);
	if (c == data->args.nb_philo - 1 && data->args.nb_tteat > 0)
		data->all_ate = 1;
}

int		check_nb_meals(t_data *data)
{
	pthread_mutex_lock(&data->mutex_nbtte);
	check_nbmeals_philo(data);
	if (data->all_ate == 1)
	{
		// printf(RED"all ate : %d\n"NORMAL, data->all_ate);
		pthread_mutex_unlock(&data->mutex_nbtte);
		// TODO : Function to end the execution correctly.
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_nbtte);
	pthread_mutex_lock(&data->mutex_nbtte);
	if (data->args.nb_tteat != -1)
	{
		pthread_mutex_unlock(&data->mutex_nbtte);
		return (0);
	}
	pthread_mutex_unlock(&data->mutex_nbtte);
	return (0);
}

int	pulse_check(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->mutex_last_meal);
	if (ft_time() - data->philo[philo->index].last_meal >= data->args.ttdie)
	{
		printf(RED"ft_time() - data->philo[%d].last_meal : %ld\n"NORMAL, i, ft_time() - data->philo[i].last_meal);
		pthread_mutex_unlock(&data->mutex_last_meal);
		ft_display_message(data, i, "died");
		data->is_dead = 1;
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_last_meal);
	return (0);
}

int		check_death(t_data *data)
{
	pthread_mutex_lock(&data->mutex_death);
	if (data->is_dead == 1)
	{
		pthread_mutex_unlock(&data->mutex_death);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_death);
	return (0);
}