/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:34:43 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/17 10:40:43 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	error(int return_value, char *msg)
{
	printf(RED "%s\n", msg);
	printf(NORMAL);
	exit(return_value);
}
