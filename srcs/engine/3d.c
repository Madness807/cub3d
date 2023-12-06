/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:49:09 by efailla           #+#    #+#             */
/*   Updated: 2023/12/06 17:50:28 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	paint_roof(t_game *game, int x)
{
	int	y;

	y = -1;
	while (++y < SCREEN_H / 2)
	{
		put_pixel_to_img(game->img, x, y,
			game->mapfile->c);
	}
}

void	paint_floor(t_game *game, int x)
{
	int	y;

	y = SCREEN_H / 2;
	while (++y < SCREEN_H)
	{
		put_pixel_to_img(game->img, x, y,
			game->mapfile->f);
	}
}

int	get_color_from_texture(t_game *game, int x, int y, int side)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	char			*str;
	int				size;

	str = game->tex[side].addr;
	size = game->tex[side].width;
	b = str[(x * 4) + (size * y * 4)];
	g = str[(x * 4) + (size * y * 4) + 1];
	r = str[(x * 4) + (size * y * 4) + 2];
	return (((int)r << 16) + ((int)g << 8) + (int)b);
}

void	print_text(t_game *game, t_var *var, t_scandale scand)
{
	int		color;
	double	r;
	double	r2;

	r = game->tex[var->line->side].height / scand.wallsize;
	r2 = var->line->x * (game->tex[var->line->side].width / CUBESIZE);
	color = get_color_from_texture(game, r2, scand.y * r, var->line->side);
	put_pixel_to_img(game->img, scand.x, scand.y + scand.lineoff, color);
}

void	draw_screen_line(t_game *game, t_var *var, double len, int x)
{
	float		ca;
	t_scandale	scand;

	scand.x = x;
	scand.y = -1;
	ca = game->player->angle - var->ra;
	ca = angle_corrector(ca);
	len = len * cos(ca);
	scand.wallsize = (CUBESIZE * SCREEN_H) / len;
	scand.lineoff = (SCREEN_H - scand.wallsize) / 2;
	paint_roof(game, x);
	paint_floor(game, x);
	while (++scand.y < scand.wallsize)
	{
		print_text(game, var, scand);
	}
}
