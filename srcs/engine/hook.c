/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:14:49 by efailla           #+#    #+#             */
/*   Updated: 2023/10/19 20:49:51 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	hook_exit(t_game *game)
{	
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	check_angle(t_game *game)
{
	if (game->player->angle == PI || game->player->angle == P2)
		game->player->angle -= 0.001;
	if (game->player->angle == P3 || game->player->angle == PI * 2)
		game->player->angle += 0.001;
}

int	key_hook(int key, t_game *game)
{
	if (key == K_ESC)
		hook_exit(game);
	else if (key == K_LEFT)
	{
		game->player->angle -= 0.1;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
		game->player->delta_x = cos(game->player->angle) * 5;
		game->player->delta_y = sin(game->player->angle) * 5;
	}
	else if (key == K_DOWN)
	{
		game->player->posx -= game->player->delta_x;
		game->player->posy -= game->player->delta_y;
	}
	else if (key == K_RIGHT)
	{
		game->player->angle += 0.1;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
		game->player->delta_x = cos(game->player->angle) * 5;
		game->player->delta_y = sin(game->player->angle) * 5;
	}
	else if (key == K_UP)
	{
		game->player->posx += game->player->delta_x;
		game->player->posy += game->player->delta_y;
	}
	//check_angle(game);
	render(game);
	return (0);
}
