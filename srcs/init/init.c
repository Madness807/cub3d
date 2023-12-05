/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:10:12 by efailla           #+#    #+#             */
/*   Updated: 2023/12/05 17:00:39 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_var	*init_var(t_game *game)
{
	t_var	*var;
	t_line	*line;

	line = malloc(sizeof(t_line) + 1000);
	var = malloc(sizeof(t_var) + 1000);
	var->line = line;
	var->r = SCREEN_W;//200 * 8;
	var->ra = game->player->angle - ((DR / 8) * var->r / 2);
	var->ra = angle_corrector(var->ra);
	return (var);
}

t_img	*create_new_img(t_game *game)
{
	t_img	*img;

	img = malloc(sizeof(t_img) + 100);
	img->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
								&img->endian);
	img->height = 0;
	img->width = 0;
	return (img);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player) + 100);
	player->angle = 0;
	player->delta_x = cos(player->angle) * 5;
	player->delta_y = sin(player->angle) * 5;

	return (player);
}

t_mapfile	*init_map_file(void)
{
	t_mapfile	*mapfile;

	mapfile = malloc(sizeof(t_mapfile) + 100);
	mapfile->map_h = 0;
	mapfile->map_tab = NULL;
	mapfile->no = NULL;
	mapfile->so = NULL;
	mapfile->ea = NULL;
	mapfile->we = NULL;
	mapfile->c = -1;
	mapfile->f = -1;
	return (mapfile);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game) + 100);
	game->mapfile = init_map_file();
	game->player = init_player();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3fesses");
	game->img = create_new_img(game);
	game->minimap = 0;
	game->mouse = 0;
	game->sprint = 0;
	mlx_mouse_move(game->win, SCREEN_W / 2, SCREEN_H / 2);
	return (game);
}
