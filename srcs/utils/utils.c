/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:18 by efailla           #+#    #+#             */
/*   Updated: 2023/11/08 15:43:22 by efailla          ###   ########.fr       */
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

int	coord_mapy(double y, int limit)
{
	int	n;

	n = (int)(y) / CUBESIZE;
	if (n > limit)
		n = limit;
	if (n < 0)
		n = 0;
	return (n);
}

int	coord_mapx(t_game *game, double x, int y)
{
	int n;
	int	i;
	int limit;

	i = 0;
	while (game->mapfile->map_tab[y][i] != 0)
		i++;
	limit = i - 1;
	n = (int)(x) / CUBESIZE;
	if (n > limit)
		n = limit;
	if (n < 0)
		n = 0;
	return (n);
}

double	return_lowest_int(double a, double b, t_game *game, t_var *var)
{
	if (a <= b)
	{
		if (var->ra > PI)
			var->line->side = SO;
		else
			var->line->side = NO;
		return (a);
	}
	else
	{
		if (var->ra > P2 && var->ra < P3)
			var->line->side = EA;
		else
			var->line->side = WE;
		return (b);
	}
}

double	angle_corrector(double angle)
{
	if (angle < 0)
			angle += 2 * PI;
	if (angle > 2 * PI)
			angle -= 2 * PI;
	return (angle);
}