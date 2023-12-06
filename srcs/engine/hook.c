/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:14:49 by efailla           #+#    #+#             */
/*   Updated: 2023/12/06 17:10:15 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ok_to_open(t_game *game)
{
	int		px;
	int		py;

	px = game->player->posx / CUBESIZE;
	py = game->player->posy / CUBESIZE;
	if (game->mapfile->map_tab[py][px] == 'D')
		return (0);
	return (1);
}

void	open_door(t_game *game)
{
	double	next_x;
	double	next_y;
	int		mx;
	int		my;

	next_x = game->player->posx + (game->player->delta_x * 15);
	next_y = game->player->posy + (game->player->delta_y * 15);
	mx = next_x / CUBESIZE;
	my = next_y / CUBESIZE;
	if (game->mapfile->map_tab[my][mx] == 'd')
		game->mapfile->map_tab[my][mx] = 'D';
	else if (game->mapfile->map_tab[my][mx] == 'D'
		&& ok_to_open(game))
		game->mapfile->map_tab[my][mx] = 'd';
}

int	mouse(int x, int y, t_game *game)
{
	double	sens;
	double	angle;
	int		dx;

	if (game->mouse == 0)
		return (0);
	(void)y;
	sens = 0.5;
	angle = game->player->angle;
	dx = x - SCREEN_W / 2;
	mlx_mouse_move(game->win, SCREEN_W / 2, SCREEN_H / 2);
	if (dx > 0)
		angle += (0.1 * sens);
	else if (dx < 0)
		angle -= (0.1 * sens);
	game->player->angle = angle_corrector(angle);
	game->player->delta_x = cos(game->player->angle) * 5;
	game->player->delta_y = sin(game->player->angle) * 5;
	render(game);
	return (0);
}

int	check_collisions(t_game *game, int key)
{
	double	next_x;
	double	next_y;
	int		mx;
	int		my;

	if (key == K_UP)
	{
		next_x = game->player->posx + (game->player->delta_x * 4);
		next_y = game->player->posy + (game->player->delta_y * 4);
	}
	else
	{
		next_x = game->player->posx - (game->player->delta_x * 4);
		next_y = game->player->posy - (game->player->delta_y * 4);
	}
	mx = next_x / CUBESIZE;
	my = next_y / CUBESIZE;
	if (game->mapfile->map_tab[my][mx] == '1' ||
		game->mapfile->map_tab[my][mx] == 'd')
		return (0);
	return (1);
}

int	check_collisions_lr(t_game *game, int key)
{
	double	next_x;
	double	next_y;
	int		mx;
	int		my;

	if (key == K_RIGHT)
	{
		next_x = game->player->posx - (game->player->delta_y * 4);
		next_y = game->player->posy + (game->player->delta_x * 4);
	}
	else
	{
		next_x = game->player->posx + (game->player->delta_y * 4);
		next_y = game->player->posy - (game->player->delta_x * 4);
	}
	mx = next_x / CUBESIZE;
	my = next_y / CUBESIZE;
	if (game->mapfile->map_tab[my][mx] == '1' ||
		game->mapfile->map_tab[my][mx] == 'd')
		return (0);
	return (1);
}
