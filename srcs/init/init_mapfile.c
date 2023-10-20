/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:10:12 by efailla           #+#    #+#             */
/*   Updated: 2023/10/20 02:19:17 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_map_file(t_game *game)
{
	game->mapfile = malloc(sizeof(t_mapfile));
	if (!game->mapfile)
		exit (1);
	
	game->mapfile->nbr_line = 0;
	game->mapfile->map_tab = NULL;
	game->mapfile->no = NULL;
	game->mapfile->so = NULL;
	game->mapfile->ea = NULL;
	game->mapfile->we = NULL;
	game->mapfile->c = NULL;
	game->mapfile->f = NULL;
}

