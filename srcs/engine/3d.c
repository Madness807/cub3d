/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:49:09 by efailla           #+#    #+#             */
/*   Updated: 2023/11/16 19:35:09 by efailla          ###   ########.fr       */
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

// int	texture_color(t_game *game, t_var *var, int x, int y)
// {
// 	int	i;
// 	unsigned int color;

// 	i = var->line->side;
// 	color = game->tex[i].addr + (y * game->tex[i].line_length + var->line->x *
// 		(game->tex[i].bpp / 8));
// }

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

void print_text(t_game *game, t_var *var, int x, int y, int lineoff, double wallsize)
{
	int color; //0xAA74D1EA
	double r;

	r = CUBESIZE / wallsize;

	color = get_color_from_texture(game, var->line->x, y * r, var->line->side);
	put_pixel_to_img(game->img, x, y + lineoff, color);
}

void	draw_screen_line(t_game *game, t_var *var, double len, int x)
{
	double	wallsize;
	int		wallwidth;
	int		y;
	int		lineoff;
	float	ca;

	ca = game->player->angle - var->ra;
	ca = angle_corrector(ca);
	len = len * cos(ca);
	y = -1;
	wallwidth = 1;
	wallsize = (CUBESIZE * SCREEN_H) / len;
	// if (wallsize >= SCREEN_H)
	// 	wallsize = SCREEN_H;
	lineoff = (SCREEN_H - wallsize) / 2;
	paint_roof(game, wallwidth, x);
	paint_floor(game, wallwidth, x);
	while (++y < wallsize)
	{
		//put_pixel_to_img(game->img, x, y + lineoff, 0x00FF0000);
		print_text(game, var, x, y, lineoff, wallsize);
	}
}
