/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:10:12 by efailla           #+#    #+#             */
/*   Updated: 2023/10/23 11:17:30 by efailla          ###   ########.fr       */
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

t_img *create_new_img(t_game *game)
{
	t_img *img;
	
	img = malloc(sizeof(t_img *) + 100);
	img->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
								&img->endian);
	return (img);
}

t_game *init_game(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	game->player = malloc(sizeof(t_player));
	game->mlx = mlx_init();
	game->mapfile = malloc(sizeof(t_mapfile *));
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3fesses");
	game->img = create_new_img(game);
	//game->img = malloc(sizeof(t_img *));
	game->map = map_alloc(game);
	game->player->posx = 750;
	game->player->posy = 750;
	game->player->angle = 0;
	game->minimap = 0;
	game->player->deltaX = cos(game->player->angle) * 5;
	game->player->deltaY = sin(game->player->angle) * 5;
	render(game);
	
	return (game);
}