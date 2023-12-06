/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:39 by efailla           #+#    #+#             */
/*   Updated: 2023/12/06 17:10:37 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
