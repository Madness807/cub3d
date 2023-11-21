/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:14:49 by efailla           #+#    #+#             */
/*   Updated: 2023/11/21 14:51:51 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	else if (game->mapfile->map_tab[my][mx] == 'D')
		game->mapfile->map_tab[my][mx] = 'd';
}

int	mouse(int x, int y, t_game *game)
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
	mx = next_x / CUBESIZE;//coord_map(next_x);
	my = next_y / CUBESIZE;//coord_map(next_y);
	if (game->mapfile->map_tab[my][mx] == '1' ||
		game->mapfile->map_tab[my][mx] == 'd')
		return (0);
	return (1);
}

int	check_collisions_LR(t_game *game, int key)
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
	mx = next_x / CUBESIZE;//coord_map(next_x);
	my = next_y / CUBESIZE;//coord_map(next_y);
	if (game->mapfile->map_tab[my][mx] == '1' ||
		game->mapfile->map_tab[my][mx] == 'd')
		return (0);
	return (1);
}

void	camera_movement(t_game *game, int key)
{
	if (key == K_ROTATE_L && game->mouse == 0)
	{
		game->player->angle -= 0.1;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
		game->player->delta_x = cos(game->player->angle) * 5;
		game->player->delta_y = sin(game->player->angle) * 5;
	}
	else if (key == K_ROTATE_R && game->mouse == 0)
	{
		game->player->angle += 0.1;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
		game->player->delta_x = cos(game->player->angle) * 5;
		game->player->delta_y = sin(game->player->angle) * 5;
	}
}

void	towards_backward_movement(t_game *game, int key)
{
	if (key == K_UP && check_collisions(game, key))
	{
		game->player->posx += game->player->delta_x;
		game->player->posy += game->player->delta_y;
	}
	else if (key == K_DOWN && check_collisions(game, key))
	{
		game->player->posx -= game->player->delta_x;
		game->player->posy -= game->player->delta_y;
	}
}

int	hook_exit(t_game *game)
{	
	mlx_destroy_window(game->mlx, game->win);
	free_all(game);
	exit(0);
}

void	side_movement(t_game *game, int key)
{
	if (key == K_LEFT && check_collisions_LR(game, key))
	{
		game->player->posx += game->player->delta_y;
		game->player->posy -= game->player->delta_x;
	}
	else if (key == K_RIGHT && check_collisions_LR(game, key))
	{
		game->player->posx -= game->player->delta_y;
		game->player->posy += game->player->delta_x;
	}
}

int	sprint_release(int key, t_game *game)
{
	if (key == K_SHIFT && game->sprint == 1)
	{
		game->sprint = 0;
		game->player->delta_x /= 2;
		game->player->delta_y /= 2;
	}
	return (0);
}

int	sprint_press(int key, t_game *game)
{
	if (key == K_SHIFT && game->sprint == 0)
	{
		game->sprint = 1;
		game->player->delta_x *= 2;
		game->player->delta_y *= 2;
	}
	return (0);
}

int	key_hook(int key, t_game *game)
{
	//printf("key: %i\n", key);
	if (key == K_ESC)
		hook_exit(game);
	else if (key == K_ROTATE_L || key == K_ROTATE_R)
		camera_movement(game, key);
	else if (key == K_DOWN || key == K_UP)
		towards_backward_movement(game, key);
	else if (key == K_LEFT || key == K_RIGHT)
		side_movement(game, key);
	else if (key == K_SHIFT)
		sprint_press(key, game);
	params(key, game);
	render(game);
	return (0);
}
