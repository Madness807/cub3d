/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:14:49 by efailla           #+#    #+#             */
/*   Updated: 2023/10/26 18:55:22 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int mouse(int x, int y, t_game *game)
{
	double	sens;
	double	angle;
	int		dx;
	// printf("coord x : %d\n", x);
	// printf("coord y : %d\n\n", y);
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
	game->player->angle =  angle_corrector(angle);
	game->player->deltaX = cos(game->player->angle) * 5;
	game->player->deltaY = sin(game->player->angle) * 5;
	render(game);
	return (0);
}

int		check_collisions(t_game *game, int key)
{
	double	next_x;
	double	next_y;
	int		mx;
	int		my;

	if (key == K_UP)
	{
		next_x = game->player->posx + (game->player->deltaX * 4);
		next_y = game->player->posy + (game->player->deltaY * 4);
	}
	else
	{
		next_x = game->player->posx - (game->player->deltaX * 4);
		next_y = game->player->posy - (game->player->deltaY * 4);
	}
	mx = next_x / CUBESIZE;//coord_map(next_x);
	my = next_y / CUBESIZE;//coord_map(next_y);
	// printf("coord x : %d\n", mx);
	// printf("coord y : %d\n\n", my);
	if (game->mapfile->map_tab[my][mx] == '1')
		return (0);
	return (1);
}

void	side_movement(t_game *game, int key)
{
	if (key == K_LEFT && game->mouse == 0)
	{
		game->player->angle -= 0.1;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
		game->player->deltaX = cos(game->player->angle) * 5;
		game->player->deltaY = sin(game->player->angle) * 5;
	}
	else if (key == K_RIGHT && game->mouse == 0)
	{
		game->player->angle += 0.1;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
		game->player->deltaX = cos(game->player->angle) * 5;
		game->player->deltaY = sin(game->player->angle) * 5;
	}
}

void	towards_backward_movement(t_game *game, int key)
{
	if (key == K_UP && check_collisions(game, key))
	{
		game->player->posx += game->player->deltaX;
		game->player->posy += game->player->deltaY;
	}
	else if (key == K_DOWN && check_collisions(game, key))
	{
		game->player->posx -= game->player->deltaX;
		game->player->posy -= game->player->deltaY;
	}
}

int	hook_exit(t_game *game)
{	
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

// void	check_angle(t_game *game)
// {
// 	if (game->player->angle == PI || game->player->angle == P2)
// 		game->player->angle -= 0.001;
// 	if (game->player->angle == P3 || game->player->angle == PI * 2)
// 		game->player->angle += 0.001;
// }

int	key_hook(int key, t_game *game)
{
	if (key == K_ESC)
		hook_exit(game);
	else if (key == K_LEFT)
		side_movement(game, key);
	else if (key == K_DOWN)
		towards_backward_movement(game, key);
	else if (key == K_RIGHT)
		side_movement(game, key);
	else if (key == K_UP)
		towards_backward_movement(game, key);
	//check_angle(game);
	render(game);
	return (0);
}
