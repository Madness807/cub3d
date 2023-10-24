/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:18 by efailla           #+#    #+#             */
/*   Updated: 2023/10/24 17:15:25 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > SCREEN_W)
		x = SCREEN_W;
	if (x < 0)
		x = 0;
	if (y > SCREEN_H)
		y = SCREEN_H;
	if (y < 0)
		y = 0;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

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