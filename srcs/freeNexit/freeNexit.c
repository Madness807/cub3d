/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeNexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:10:12 by efailla           #+#    #+#             */
/*   Updated: 2023/11/20 13:56:59 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	destroy_text(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(game->mlx, game->tex[i].img);
	mlx_destroy_image(game->mlx, game->img);
}

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (game->mapfile->map_tab[++i] != 0)
		free(game->mapfile->map_tab[i]);
	free(game->mapfile->map_tab);
	free(game->mapfile);
}

void	free_all(t_game *game)
{
	destroy_text(game);
	free(game->player);
	free_map(game);
	free(game);
}
/*
void    free_exit(t_game *game)
{
    
    free(game->mapfile->color_celling);
    free(game->mapfile->color_floor);

    free(game->mapfile);

    free(game);

    return ;
}
*/

