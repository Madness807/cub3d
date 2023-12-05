/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:49:09 by efailla           #+#    #+#             */
/*   Updated: 2023/12/05 17:53:29 by joterret         ###   ########.fr       */
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

void	print_text(t_game *game, t_var *var, int x, int y, int lineoff, double wallsize)
{
	int		color;
	double	r;
	double	r2;

	r = game->tex[var->line->side].height / wallsize;
	r2 = var->line->x * (game->tex[var->line->side].width / CUBESIZE);
	color = get_color_from_texture(game, r2, y * r, var->line->side);
	put_pixel_to_img(game->img, x, y + lineoff, color);
}

void	draw_screen_line(t_game *game, t_var *var, double len, int x)
{
	double	wallsize;
	int		y;
	int		lineoff;
	float	ca;

	ca = game->player->angle - var->ra;
	ca = angle_corrector(ca);
	len = len * cos(ca);
	y = -1;
	wallsize = (CUBESIZE * SCREEN_H) / len;
	lineoff = (SCREEN_H - wallsize) / 2;
	paint_roof(game, x);
	paint_floor(game, x);
	while (++y < wallsize)
	{
		print_text(game, var, x, y, lineoff, wallsize);
	}
}
