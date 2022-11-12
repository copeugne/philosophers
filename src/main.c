/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:06:20 by copeugne          #+#    #+#             */
/*   Updated: 2022/11/12 11:19:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_datastruct(&data);
	check_args(argc, argv, &data);
	init_mutex(&data);
	init_philo_threads(&data);
	pulse_check(&data);
	thread_joiner(&data);
	mutex_destroyer(&data);
	return (0);
}
