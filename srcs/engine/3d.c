/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:49:09 by efailla           #+#    #+#             */
/*   Updated: 2023/10/19 07:03:00 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_screen_line(t_game *game, t_var *var, double len, int x)
{
	double	wallsize;
	int		wallwidth;
	int	y;
	int i;
	int lineoff;
	float ca;

	ca = game->player->angle - var->ra;
	ca = angle_corrector(ca);
	len = len * cos(ca);
	y = -1;
	i = -1;
	wallwidth = SCREEN_W / FOV;
	wallsize = (CUBESIZE * SCREEN_H) / len;
	lineoff = (SCREEN_H - wallsize) / 2;
	//printf("len : %lf\n", len);
	if (wallsize > SCREEN_H)
		wallsize = SCREEN_H;
	// while (y < (SCREEN_H - wallsize) / 2)
	// 	y++;
	while (++y < wallsize)
	{
		while (++i < wallwidth)
			put_pixel_to_img(game->img, i + (wallwidth * x), y + lineoff, game->color);
		i = -1;
	}
}

// void	draw_screen(t_game *game, t_var *var, double len, int x)
// {
	
// }