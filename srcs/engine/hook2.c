/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:45:46 by efailla           #+#    #+#             */
/*   Updated: 2023/12/06 17:10:06 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	hook_exit(t_game *game)
{	
	mlx_destroy_window(game->mlx, game->win);
	free_all(game);
	exit(0);
}

void	side_movement(t_game *game, int key)
{
	if (key == K_LEFT && check_collisions_lr(game, key))
	{
		game->player->posx += game->player->delta_y;
		game->player->posy -= game->player->delta_x;
	}
	else if (key == K_RIGHT && check_collisions_lr(game, key))
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
