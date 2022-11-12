/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:28:37 by copeugne          #+#    #+#             */
/*   Updated: 2022/11/12 11:19:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/**
 * It checks the arguments passed to the program
 * and loads them into the args struct
 * 
 * @param argc The number of arguments passed to the program.
 * @param argv The array of arguments passed to the program.
 * @param data a pointer to the data structure
 * 
 * @return 0
 */
int	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		error(11, "Error check_args 1: Incorrect number of arguments\n");
	if (load_args(argc, argv, data))
		error(12, "Error check_args 2: Incorrect argument values\n");
	return (0);
}

/**
 * It loads the arguments from the command line into the `t_args` structure
 * 
 * @param argc the number of arguments passed to the program
 * @param argv The array of arguments passed to the program
 * @param args the structure that contains all the parsed arguments
 * 
 * @return 0.
 */
int	load_args(int argc, char **argv, t_data *data)
{
	data->args.nb_philo = ft_atoi(argv[1]);
	data->args.ttdie = ft_atoi(argv[2]);
	data->args.tteat = ft_atoi(argv[3]);
	// printf("args 1 = %d\n", data->args.nb_philo);
	// printf("args 2 = %d\n", data->args.ttdie);
	// printf("args 3 = %d\n", data->args.tteat);
	if (data->args.tteat > data->args.ttdie)
		data->args.tteat = data->args.ttdie + 10;
	data->args.ttsleep = ft_atoi(argv[4]);
	// printf("args 4 = %d\n", data->args.ttsleep);
	if (data->args.nb_philo < 1 || data->args.nb_philo > 200
		|| data->args.ttdie < 0 || data->args.tteat < 0
		|| data->args.ttsleep < 0)
		error(21, "Error load_data->args 1: Incorrect argument values\n");
	if (argc == 6)
	{
		data->args.nb_tteat = ft_atoi(argv[5]);
		if (data->args.nb_tteat < 0)
			error(22, "Error load_data->args 2: Incorrect argument values\n");
	}
	else
		data->args.nb_tteat = -1;
	return (0);
}
