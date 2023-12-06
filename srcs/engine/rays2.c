/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:28 by efailla           #+#    #+#             */
/*   Updated: 2023/12/06 17:55:18 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_rays(t_game *game, int depth, t_var *var)
{
	int		x;
	int		y;
	int		len;
	double	angle;

	x = (int)game->player->posx;
	y = (int)game->player->posy;
	angle = var->ra;
	len = 1;
	while (++len < depth)
		put_pixel_to_img(game->img, (int)(cos(angle) * len + x),
			(int)(sin(angle) * len + y), 0x00EF95CF);
}

void	draw_direction(t_game *game, int depth)
{
	int		x;
	int		y;
	int		len;
	double	angle;

	x = (int)game->player->posx / 10 + MAP_OFFSET;
	y = (int)game->player->posy / 10 + MAP_OFFSET;
	angle = game->player->angle;
	len = 1;
	while (++len < depth)
		put_pixel_to_img(game->img, (int)(cos(angle) * len + x),
			(int)(sin(angle) * len + y), 0x00FF0000);
}

int	check_ray_len(int ax, int ay, int bx, int by)
{
	int	len;

	len = ((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by));
	return (len);
}
