/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:49:09 by efailla           #+#    #+#             */
/*   Updated: 2023/11/08 13:50:32 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	paint_roof(t_game *game, int wallwidth, int x)
{
	int	y;
	int	i;
	y = -1;
	i = -1;

	while (++y < SCREEN_H / 2)
	{
		while (++i < wallwidth)
			put_pixel_to_img(game->img, i + (wallwidth * x), y,
					game->mapfile->c);
		i = -1;
	}
}

void	paint_floor(t_game *game, int wallwidth, int x)
{
	int	y;
	int	i;

	y = SCREEN_H / 2;
	i = -1;
	while (++y < SCREEN_H)
	{
		while (++i < wallwidth)
			put_pixel_to_img(game->img, i + (wallwidth * x), y,
					game->mapfile->f);
		i = -1;
	}
}

void	draw_screen_line(t_game *game, t_var *var, double len, int x)
{
	double	wallsize;
	int		wallwidth;
	int		y;
	int		i;
	int		lineoff;
	float	ca;

	ca = game->player->angle - var->ra;
	ca = angle_corrector(ca);
	len = len * cos(ca);
	y = -1;
	i = -1;
	wallwidth = SCREEN_W / FOV;
	wallsize = (CUBESIZE * SCREEN_H) / len;
	if (wallsize >= SCREEN_H)
		wallsize = SCREEN_H;
	lineoff = (SCREEN_H - wallsize) / 2;
	paint_roof(game, wallwidth, x);
	paint_floor(game, wallwidth, x);
	while (++y < wallsize)
	{
		while (++i < wallwidth)
			put_pixel_to_img(game->img, i + (wallwidth * x), y + lineoff, game->color);
		i = -1;
	}
}
