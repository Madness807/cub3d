/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:45:31 by efailla           #+#    #+#             */
/*   Updated: 2023/11/01 20:03:39 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	reset_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (game->mapfile->map_tab[++y] != 0)
	{
		while (game->mapfile->map_tab[y][++x] != 0)
		{
			if (game->mapfile->map_tab[y][x] == 'D')
				game->mapfile->map_tab[y][x] = 'd';
			else if (game->mapfile->map_tab[y][x] == 'x')
				game->mapfile->map_tab[y][x] = '0';
		}
		x = -1;
	}
}

void	check_possible_path(t_game *game, int x, int y)
{
	if (game->mapfile->map_tab[y][x] == '1' ||
		game->mapfile->map_tab[y][x] == 'x' ||
		game->mapfile->map_tab[y][x] == 'D')
		return ;
	if (game->mapfile->map_tab[y][x] != '0' && !is_player(game, x, y) &&
			game->mapfile->map_tab[y][x] != 'd')
		print_error("map is not surrounded by walls\n");
	if (game->mapfile->map_tab[y][x] == 'd')
		game->mapfile->map_tab[y][x] = 'D';
	else
		game->mapfile->map_tab[y][x] = 'x';
	check_possible_path(game, x - 1, y);
	check_possible_path(game, x + 1, y);
	check_possible_path(game, x, y + 1);
	check_possible_path(game, x, y - 1);
}

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