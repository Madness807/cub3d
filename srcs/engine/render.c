/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:16:26 by efailla           #+#    #+#             */
/*   Updated: 2023/12/05 18:09:12 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_cubes(t_game *game, int x, int y, int color)
{
	int	x1;
	int	y1;

	x1 = -1;
	y1 = -1;
	while (++x1 < 10)
	{
		while (++y1 < 10)
			put_pixel_to_img(game->img, (x * 10) + x1 + MAP_OFFSET, (y * 10) + y1 + MAP_OFFSET, color);
		y1 = -1;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (game->mapfile->map_tab[y][x] != 0)
	{
		while (game->mapfile->map_tab[y] != 0)
		{
			color = w_colors(game, x, y);
			if (color != 0)
				draw_cubes(game, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void	render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ray_caster(game);
	if (game->minimap == 1)
	{
		draw_map(game);
		draw_player(game);
		draw_direction(game, 20);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img->img);
	game->img->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp,
			&game->img->line_length, &game->img->endian);
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;
	int	playerposx;
	int	playerposy;

	playerposx = (int)game->player->posx / 10 + MAP_OFFSET;
	playerposy = (int)game->player->posy / 10 + MAP_OFFSET;
	x = -1;
	y = -1;
	while (++x < 6)
	{
		while (y++ < 6)
			put_pixel_to_img(game->img, (playerposx - 3) + x,
				(playerposy - 3) + y, 0x00FF00FF);
		y = -1;
	}
}
