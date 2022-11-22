/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:26:08 by copeugne          #+#    #+#             */
/*   Updated: 2022/11/22 19:22:27 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/**
 * It checks if all the philosophers have eaten
 * the number of meals they were supposed to eat
 * 
 * @param data the structure containing all the data
 */
void	check_nbmeals_philo(t_data *data)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if (data->args.nb_tteat == 0)
		data->all_ate = 1;
	while (i < data->args.nb_philo - 1)
	{
		if (data->philo[i].nb_meals >= data->args.nb_tteat)
			c++;
		i++;
	}
	if (c == data->args.nb_philo - 1 && data->args.nb_tteat > 0)
		data->all_ate = 1;
}

/**
 * It checks if the number of meals has been
 * reached and if so, it returns 1
 * 
 * @param data the structure containing all the data
 */
int	check_nb_meals(t_data *data)
{
	pthread_mutex_lock(&data->mutex_nbtte);
	check_nbmeals_philo(data);
	if (data->all_ate == 1)
	{
		pthread_mutex_unlock(&data->mutex_nbtte);
		pthread_mutex_lock(&data->mutex_death);
		data->is_dead = 1;
		pthread_mutex_unlock(&data->mutex_death);
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

void	grim_reaper(t_data *data)
{
	pthread_mutex_lock(&data->mutex_death);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->mutex_death);
}

/**
 * It checks if a philosopher is still alive
 * or if he died of starvation
 * 
 * @param data the structure containing all the data
 */
int	pulse_check(t_data *data, int i, long int t)
{
	t_copy		copy;

	if (data->args.nb_philo == 1)
		return (0);
	while (!check_death(data))
	{
		pthread_mutex_lock(&data->mutex_last_meal);
		copy = *((t_copy *)(data->philo + i));
		pthread_mutex_unlock(&data->mutex_last_meal);
		if (ft_time() - copy.last_meal >= data->args.ttdie
			&& copy.last_meal != -1)
		{
			t = ft_now(copy.start_time);
			grim_reaper(data);
			pthread_mutex_lock(&data->mutex_write);
			printf("%lu %d %s\n", t, copy.index, "died");
			pthread_mutex_unlock(&data->mutex_write);
			return (1);
		}
		usleep(1000);
		i++;
		if (i == data->args.nb_philo)
			i = 0;
	}
	return (0);
}

int	check_death(t_data *data)
{
	int	is_dead;

	pthread_mutex_lock(&data->mutex_death);
	is_dead = data->is_dead;
	pthread_mutex_unlock(&data->mutex_death);
	return (is_dead);
}
