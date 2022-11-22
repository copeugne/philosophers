/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:38:06 by copeugne          #+#    #+#             */
/*   Updated: 2022/11/22 17:19:56 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/**
 * It returns the time elapsed since the start_time.
 * 
 * @param start_time The time that you want to start counting from.
 * 
 * @return The time in milliseconds since the start time.
 */
long	ft_now(long start_time)
{
	return (ft_time() - start_time);
}

/**
 * It returns the number of milliseconds
 * elapsed since Jan 1 1970
 * 
 * @return The time in milliseconds.
 */
long	ft_time(void)
{
	struct timeval	time;
	long int		t;

	gettimeofday(&time, (void *)0);
	t = time.tv_sec * 1000;
	t += time.tv_usec / 1000;
	return (t);
}

/**
 * Ft_usleep() is a function that takes an integer
 * as an argument and sleeps the number of
 * milliseconds given
 * 
 * @param ttds is the Time To Do Something
 * (eat, sleep, think)
 */
int	ft_usleep(t_data *data, int ttds)
{
	long	now;

	now = ft_time();
	while (ft_time() - now < ttds)
	{
		if (check_death(data))
			break ;
		usleep(1000);
	}
	return (0);
}
