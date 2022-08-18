/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:50:10 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/18 16:06:28 by copeugne         ###   ########.fr       */
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
	data->philo->nb_meals++;
	fork_unlocker(data, philo);
}