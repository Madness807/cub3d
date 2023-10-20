/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:10:12 by efailla           #+#    #+#             */
/*   Updated: 2023/10/20 17:35:04 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

t_img	*create_new_img(t_game *game)
{
	t_img	*img;

	img = malloc(sizeof(t_img *) + 100);
	img->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
								&img->endian);
	return (img);
}

void	init_game(t_game *game)
{
	//SECTION - MALLOC STRUCTURE PRINCIPAL
	game = malloc(sizeof(t_game));

	//SECTION - INIT STRUCTURE PRINCIPAL
	game->player = malloc(sizeof(t_player));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3fesses");
	game->img = create_new_img(game);
	//game->img = malloc(sizeof(t_img *));
	//game->map = map_alloc(game);

	//SECTION - INIT STRUCUTRE PLAYER
	game->player->posx = 750;
	game->player->posy = 750;
	game->player->angle = 0;
	game->player->delta_x = cos(game->player->angle) * 5;
	game->player->delta_y = sin(game->player->angle) * 5;

	//SECTION - INIT STRUCTURE IMG
	/*
	game->img->img = 0;
	game->img->addr = 0;
	game->img->bpp = 0;
	game->img->line_length = 0;
	game->img->endian = 0;
	*/

	render(game);
	return ;
}
