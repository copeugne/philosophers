/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:06:57 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/18 15:33:24 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*routine_philo(void *thread_arg)
{
	t_philo *philo;
	t_data	*data;
	
	philo = (t_philo *)thread_arg;
	data = (t_data *)philo->data;

	sub_sleep(data, philo);
	// while (!is_end(data))
	// {
	// 	sub_eat(data, philo);
	// 	ft_display_message(data, philo->index, "is thinking\n");
	// }
	return (0);
}

