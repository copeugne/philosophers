/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:26:08 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/18 15:26:28 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int		check_nb_meals(t_data *data)
{
	pthread_mutex_lock(&data->mutex_nbtte);
	if (data->is_full)
	{
		pthread_mutex_unlock(&data->mutex_nbtte);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_nbtte);
	return (0);
}

int		check_death(t_data *data)
{
	pthread_mutex_lock(&data->mutex_death);
	if (data->is_dead)
	{
		pthread_mutex_unlock(&data->mutex_death);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_death);
	return (0);
}