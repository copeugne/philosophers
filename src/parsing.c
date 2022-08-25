/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:28:37 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/24 12:32:24 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		error(11, "Error check_args 1: Incorrect number of arguments\n");
	if (load_args(argc, argv, &data->args))
		error(12, "Error check_args 2: Incorrect argument values\n");
	return (0);
}

int	load_args(int argc, char **argv, t_args *args)
{
	args->nb_philo = ft_atoi(argv[1]);
	args->ttdie = ft_atoi(argv[2]);
	args->tteat = ft_atoi(argv[3]);
	args->ttsleep = ft_atoi(argv[4]);
	if (args->nb_philo < 0 || args->nb_philo > 200
		|| args->ttdie < 0 || args->tteat < 0
		|| args->ttsleep < 0)
		error(21, "Error load_args 1: Incorrect argument values\n");
	if(argc == 6)
	{
		args->nb_tteat = ft_atoi(argv[5]);
		if (args->nb_tteat < 0)
			error(22, "Error load_args 2: Incorrect argument values\n");
	}
	else
		args->nb_tteat = -1;
	return (0);
}
