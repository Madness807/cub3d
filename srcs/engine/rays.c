/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:17:03 by efailla           #+#    #+#             */
/*   Updated: 2023/11/18 17:34:46 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

	x = (int)game->player->posx / 10;
	y = (int)game->player->posy / 10;
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

double	check_vertical(t_game *game, t_var *var, double aTan)
{
	double	len;

	aTan = -tan(var->ra);
	if (var->ra > P2 && var->ra < P3)
	{
		var->rx = ((int)(game->player->posx / CUBESIZE)) * CUBESIZE - 0.0001;
		var->ry = (game->player->posx - var->rx) * aTan + game->player->posy;
		var->xo = -CUBESIZE;
		var->yo = -var->xo * aTan; 
	}
	if (var->ra < P2 || var->ra > P3)
	{
		var->rx = ((int)(game->player->posx / CUBESIZE)) * CUBESIZE + CUBESIZE;
		var->ry = (game->player->posx - var->rx) * aTan + game->player->posy;
		var->xo = CUBESIZE;
		var->yo = -var->xo * aTan;
		
	}
	if (var->ra == PI || var->ra == 0)
	{
		var->rx = game->player->posx;
		var->ry = game->player->posy;
		var->dof = 10;
	}
	len = ray_collision(game, var, 0);
	var->dof = 0;
	return (len);
}

double	check_horizontal(t_game *game, t_var *var, double aTan)
{
	double	len;

	if (var->ra > PI)
	{
		var->ry = ((int)(game->player->posy / CUBESIZE)) * CUBESIZE - 0.0001;
		var->rx = (game->player->posy - var->ry) * aTan + game->player->posx;
		var->yo = -CUBESIZE;
		var->xo = -var->yo * aTan; 
	}
	if (var->ra < PI)
	{
		var->ry = ((int)(game->player->posy / CUBESIZE)) * CUBESIZE + CUBESIZE;
		var->rx = (game->player->posy - var->ry) * aTan + game->player->posx;
		var->yo = CUBESIZE;
		var->xo = -var->yo * aTan;
	}
	if (var->ra == PI || var->ra == 0)
	{
		var->rx = game->player->posx;
		var->ry = game->player->posy;
		var->dof = 10;
	}
	len = ray_collision(game, var, 1);
	var->len = len;
	var->dof = 0;
	return (len);
}

void	ray_caster(t_game *game)
{
	int		i;
	double	len[3];
	double	aTan;
	t_var	*var;

	var = init_var(game);
	i = -1;
	while (++i < var->r)
	{
		aTan = -1/tan(var->ra);
		game->color = 0x0000B08B;
		// len = return_lowest_int(check_horizontal(game, var, aTan),
		// 		check_vertical(game, var, aTan), game, var);
		len[1] = check_horizontal(game, var, aTan);
		len[2] = check_vertical(game, var, aTan);
		len[0] = return_lowest_int(len[1], len [2], game, var);
		draw_screen_line(game, var, len[0], i);
		var->ra += DR / 8;
		var->ra = angle_corrector(var->ra);
		var->line->side = -1;
	}
	free(var->line);
	free(var);
}
