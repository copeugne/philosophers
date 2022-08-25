/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:26:08 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/25 11:56:16 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

# define MINI	-2147483648
# define MAXI	2147483647
# define RED	"\033[00;31m"
# define YELLOW	"\033[00;33m"
# define BLUE	"\033[00;34m"
# define GREEN	"\033[00;32m"
# define NORMAL	"\033[00m"
# define NB		200

typedef struct s_data t_data;
typedef struct s_args t_args;
typedef struct s_philo t_philo;

struct s_args
{
	int nb_philo;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	nb_tteat;
};

struct s_philo
{
	int			index;
	long		start_time;
	pthread_t	philo_thread;
	t_args		args;
	void		*data;
	int			nb_meals;
	long		last_meal;
};

struct s_data
{
	t_args 			args;
	t_philo			philo[NB];
	pthread_mutex_t	mutex_fork[NB];
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_nbtte;
	int				is_dead;
	int				all_ate;
};

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_usleep(int ttds);
long	ft_time();
long	ft_now(long start_time);

int		init_mutex(t_data *data);
int		mutex_destroyer(t_data *data);
int		fork_locker(t_data *data, t_philo *philo);
int		fork_unlocker(t_data *data, t_philo *philo);

void	init_datastruct(t_data *data);
int		init_philo_index(t_data *data);
int		init_philo_threads(t_data *data);
int		thread_joiner(t_data *data);

int		error(int return_value, char *msg);
int		check_args(int argc, char **argv, t_data *data);
int		load_args(int argc, char **argv, t_args *args);

void	*routine_philo(void *thread_arg);
void	sub_sleep(t_data *data, t_philo *philo);
void	sub_eat(t_data *data, t_philo *philo);

void	ft_display_message(t_data *data, int index, char *msg);


int		check_nb_meals(t_data *data);
int		pulse_check(t_data *data, t_philo *philo);
int		check_death(t_data *data);
int		is_end(t_data *data);

#endif