/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:45:31 by efailla           #+#    #+#             */
/*   Updated: 2023/10/30 19:22:04 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_player(t_game *game, int x, int y)
{
	if (game->mapfile->map_tab[y][x] == 'W' ||
		game->mapfile->map_tab[y][x] == 'N' ||
		game->mapfile->map_tab[y][x] == 'S' ||
		game->mapfile->map_tab[y][x] == 'E')
		return (1);
	return (0);
}

void	only_one_player(t_game *game)
{
	int	x;
	int	y;
	int	player_count;

	x = -1;
	y = -1;
	player_count = 0;
	while (game->mapfile->map_tab[++y] != 0)
	{
		while (game->mapfile->map_tab[y][++x] != 0)
		{
			if (is_player(game, x, y))
				player_count++;
		}
		x = -1;
	}
	if (player_count > 1)
		print_error("There is more than 1 player in the map\n");
}