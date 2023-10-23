/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:16:26 by efailla           #+#    #+#             */
/*   Updated: 2023/10/23 10:08:43 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void draw_cubes(t_game *game, int x, int y, int color)
{
	// int x1;
	// int y1;

	// x1 = -1;
	// y1 = -1;
	// while (++x1 < CUBESIZE - 1)      //EN GRAND
	// {
	// 	while (++y1 < CUBESIZE - 1)
	// 		put_pixel_to_img(game->img, (x * CUBESIZE) + x1, (y * CUBESIZE) + y1, color);
	// 	y1 = -1;
	// }
	int x1;
	int y1;

	x1 = -1;
	y1 = -1;
	while (++x1 < 20)
	{
		while (++y1 < 20)
			put_pixel_to_img(game->img, (x * 20) + x1, (y * 20) + y1, color);
		y1 = -1;
	}
}

void draw_map(t_game *game)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < 10) //largeur map
	{
		while (++y < 10)// hauteur map
			draw_cubes(game, x, y, w_colors(game, x, y));
		y = -1;
	}
}

void	render(t_game *game)
{
	//clear la fenetre
	mlx_clear_window(game->mlx, game->win);
	//ma fonction pour dessiner, dessiner dans un t_img
	ray_caster(game);
	draw_map(game);
	draw_player(game);
	draw_direction(game, 20);
	//push ton img sur la window
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	//free img
	//free(game->img);
	//reinit img
	mlx_destroy_image(game->mlx, game->img->img);
	game->img->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp, &game->img->line_length,
								&game->img->endian);
	//game->img = create_new_img(game);
}

void	draw_player(t_game *game)
{
	// int x;
	// int	y;
	// int	playerposX;                    //EN GRAND
	// int	playerposY;

	// playerposX = (int)game->player->posx;
	// playerposY = (int)game->player->posy;
	// x = -1;
	// y = -1;
	// while (++x < CUBESIZE)
	// {
	// 	while (y++ < 10)
	// 		put_pixel_to_img(game->img, (playerposX - 5) + x, (playerposY - 5) + y, 0x00FF00FF);
	// 	y = -1;
	// }
	int x;
	int	y;
	int	playerposX;
	int	playerposY;

	playerposX = (int)game->player->posx / 5; //screenW / 20
	playerposY = (int)game->player->posy / 5; // screen H / 20
	x = -1;
	y = -1;
	while (++x < 6)
	{
		while (y++ < 6)
			put_pixel_to_img(game->img, (playerposX - 3) + x, (playerposY - 3) + y, 0x00FF00FF);
		y = -1;
	}
}