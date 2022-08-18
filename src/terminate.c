/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:47:08 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/18 16:08:15 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int		is_end(t_data *data)
{
	if (check_death(data) || check_nb_meals(data))
		return (0);
	return (1);
}

int	thread_joiner(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.nb_philo)
	{
		if(pthread_join(data->philo[i].philo_thread, NULL) != 0)
			error(61, "Error thread_joiner : Issue in pthread join");
		i++;
	}
	return (0);
}
