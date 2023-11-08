/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:01 by efailla           #+#    #+#             */
/*   Updated: 2023/11/08 13:50:32 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	free_text_path(t_game *game)
{
	free(game->mapfile->ea);
	free(game->mapfile->no);
	free(game->mapfile->we);
	free(game->mapfile->so);
}

void	get_texture_data(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->tex[i].addr = mlx_get_data_addr(game->tex[i].img,
				&game->tex[i].bpp, &game->tex[i].line_length,
				&game->tex[i].endian);
	}
}

void	load_textures(t_game *game)
{
	int	i;
	
	i = -1;
	game->tex[NO].img = mlx_xpm_file_to_image(game->mlx, game->mapfile->no,
				&game->tex[NO].width, &game->tex[NO].height);
	game->tex[WE].img = mlx_xpm_file_to_image(game->mlx, game->mapfile->we,
				&game->tex[WE].width, &game->tex[WE].height);
	game->tex[EA].img = mlx_xpm_file_to_image(game->mlx, game->mapfile->ea,
				&game->tex[EA].width, &game->tex[EA].height);
	game->tex[SO].img = mlx_xpm_file_to_image(game->mlx, game->mapfile->so,
				&game->tex[SO].width, &game->tex[SO].height);
	free_text_path(game);
	get_texture_data(game);
}
