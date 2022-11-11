/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:34:43 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/26 09:13:45 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/**
 * It prints a message and exits the program
 * with the error code
 * 
 * @param return_value The value to return.
 * @param msg The message to print.
 */
int	error(int return_value, char *msg)
{
	printf(RED "%s\n", msg);
	printf(NORMAL);
	exit(return_value);
}
