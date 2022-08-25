/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:25:27 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/25 11:25:45 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check(const char **str)
{
	int	sign;

	sign = 0;
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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = check(&str);
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

void	ft_display_message(t_data *data, int index, char *msg)
{
	long int t;

	t = ft_now(data->philo[index].start_time);
	if (!is_end(data))
	{
		pthread_mutex_lock(&data->mutex_write);
		printf("%lu %d %s\n", t, index, msg);
		pthread_mutex_unlock(&data->mutex_write);
	}
}
