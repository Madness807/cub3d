/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:17:03 by efailla           #+#    #+#             */
/*   Updated: 2023/12/06 17:55:03 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	infinite_ray(t_game *game, t_var *var)
{
	var->rx = game->player->posx;
	var->ry = game->player->posy;
	var->dof = 10;
}

double	check_vertical(t_game *game, t_var *var, double atan)
{
	double	len;

	atan = -tan(var->ra);
	if (var->ra > P2 && var->ra < P3)
	{
		var->rx = ((int)(game->player->posx / CUBESIZE)) * CUBESIZE - 0.0001;
		var->ry = (game->player->posx - var->rx) * atan + game->player->posy;
		var->xo = -CUBESIZE;
		var->yo = -var->xo * atan;
	}
	if (var->ra < P2 || var->ra > P3)
	{
		var->rx = ((int)(game->player->posx / CUBESIZE)) * CUBESIZE + CUBESIZE;
		var->ry = (game->player->posx - var->rx) * atan + game->player->posy;
		var->xo = CUBESIZE;
		var->yo = -var->xo * atan;
	}
	if (var->ra == PI || var->ra == 0)
		infinite_ray(game, var);
	len = ray_collision(game, var, 0);
	var->dof = 0;
	return (len);
}

double	check_horizontal(t_game *game, t_var *var, double atan)
{
	double	len;

	if (var->ra > PI)
	{
		var->ry = ((int)(game->player->posy / CUBESIZE)) * CUBESIZE - 0.0001;
		var->rx = (game->player->posy - var->ry) * atan + game->player->posx;
		var->yo = -CUBESIZE;
		var->xo = -var->yo * atan;
	}
	if (var->ra < PI)
	{
		var->ry = ((int)(game->player->posy / CUBESIZE)) * CUBESIZE + CUBESIZE;
		var->rx = (game->player->posy - var->ry) * atan + game->player->posx;
		var->yo = CUBESIZE;
		var->xo = -var->yo * atan;
	}
	if (var->ra == PI || var->ra == 0)
		infinite_ray(game, var);
	len = ray_collision(game, var, 1);
	var->len = len;
	var->dof = 0;
	return (len);
}

void	ray_caster(t_game *game)
{
	int		i;
	double	len[3];
	double	atan;
	t_var	*var;

	var = init_var(game);
	i = -1;
	while (++i < var->r)
	{
		atan = -1 / tan(var->ra);
		game->color = 0x0000B08B;
		len[1] = check_horizontal(game, var, atan);
		len[2] = check_vertical(game, var, atan);
		len[0] = return_lowest_int(len[1], len [2], game, var);
		draw_screen_line(game, var, len[0], i);
		var->ra += DR / 8;
		var->ra = angle_corrector(var->ra);
		var->line->side = -1;
	}
	free(var->line);
	free(var);
}
