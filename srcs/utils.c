/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:18 by efailla           #+#    #+#             */
/*   Updated: 2023/10/20 17:36:54 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int coord_map(double x)
{
	int n;
	int limit;

	limit = CUBESIZE / 10 - 1;
	n = (int)(x) / CUBESIZE;
	if (n > limit)
		n = limit;
	if (n < 0)
		n = 0;
	return (n);
}

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