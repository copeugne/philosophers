/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:25:27 by copeugne          #+#    #+#             */
/*   Updated: 2022/11/12 11:30:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/**
 * It checks for whitespaces and signs
 * and then returns the sign
 * 
 * @param str This is the string that we're going to be parsing.
 * 
 * @return The sign of the number.
 */
int	check(const char **str)
{
	int	sign;
	int	len = 0;

	sign = 0;
	len = ft_strlen(*str);
	if (len < 2 && (**str < '0' || **str > '9'))
		error(33, "Error ft_atoi : Not a digit\n");
	while (**str == '\n' || **str == '\v' || **str == '\t'
		|| **str == ' ' || **str == '\f' || **str == '\r')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = 1;
		(*str)++;
	}
	return (sign);
}

/**
 * It returns 1 if the passed character
 * is a digit and 0 if it is not
 * 
 * @param c The character to be checked.
 * 
 * @return 1 if the character is a digit, 0 if not.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/**
 * It converts a string representation of an
 * int to an integer
 * 
 * @param str The string to be converted.
 * 
 * @return the number converted.
 */
int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = check(&str);
	if (sign != 1 && sign != 0)
		error(31, "Error ft_atoi : Not an int\n");
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (!sign && nb > (unsigned int)MAXI)
			return (-1);
		else if (nb > (unsigned int)MINI)
			return (0);
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (str[i] && str[i] != 32 && !ft_isdigit(str[i]))
		error(31, "Error ft_atoi : Not a digit\n");
	if (sign == 0)
		return ((int)nb);
	return ((int)-nb);
}

/**
 * It displays a message on the screen
 * 
 * @param data the structure containing all the data
 * @param index the index of the philosopher
 * @param msg the message to display
 */
void	ft_display_message(t_data *data, int index, char *msg)
{
	long int t;

	t = ft_now(data->philo[index].start_time);
	// pthread_mutex_lock(&data->mutex_death);
	if (!is_end(data))
	{
		// pthread_mutex_unlock(&data->mutex_death);
		pthread_mutex_lock(&data->mutex_write);
		printf("%lu %d %s\n", t, index, msg);
		pthread_mutex_unlock(&data->mutex_write);
	}
}
