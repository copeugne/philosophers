/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:38:06 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/18 09:53:11 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long ft_now(long start_time)
{
	return (ft_time() - start_time);
}

long ft_time()
{
	struct timeval time;
	long int t;

	gettimeofday(&time, (void *)0);
	t = time.tv_sec * 1000;
	t += time.tv_usec / 1000;
	return (t);
}

int	ft_usleep(/*t_data *data, t_philo *philo,*/ int ttds)
{
	long now;

	now = ft_time();
	while (ft_time() - now < ttds)
		usleep(100);
	return (0);
}
