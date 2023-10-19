/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:18 by efailla           #+#    #+#             */
/*   Updated: 2023/10/19 06:59:26 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	return_lowest_int(double a, double b, t_game *game)
{
	// printf("horizontal len : %d\n", a);
	// printf("vertical len : %d\n\n", b);
	if (a <= b)
	{
		game->color = 0x0000AB84;
		return (a);
	}
	else
		return (b);
}

double	angle_corrector(double angle)
{
	if (angle < 0)
			angle += 2 * PI;
	if (angle > 2 * PI)
			angle -= 2 * PI;
	return (angle);
}