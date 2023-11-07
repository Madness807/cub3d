/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:01 by efailla           #+#    #+#             */
/*   Updated: 2023/11/07 16:38:38 by efailla          ###   ########.fr       */
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
		game->tex[i].texture->addr = mlx_get_data_addr(game->tex[i].texture->img,
				&game->tex[i].texture->bpp, &game->tex[i].texture->line_length,
				&game->tex[i].texture->endian);
	}
}

void load_textures(t_game *game)
{
	int	i;
	
	i = -1;
	while (++i < 4)
	{
		game->tex[i].texture = malloc(sizeof(t_img) + 100);
		game->tex[i].height = 100;
		game->tex[i].width = 100;
	}
	game->tex[NO].texture->img = mlx_xpm_file_to_image(game->mlx, game->mapfile->no,
				&game->tex[NO].width, &game->tex->height);
	game->tex[WE].texture->img = mlx_xpm_file_to_image(game->mlx, game->mapfile->we,
				&game->tex[WE].width, &game->tex->height);
	game->tex[EA].texture->img = mlx_xpm_file_to_image(game->mlx, game->mapfile->ea,
				&game->tex[EA].width, &game->tex->height);
	game->tex[SO].texture->img = mlx_xpm_file_to_image(game->mlx, game->mapfile->so,
				&game->tex[SO].width, &game->tex->height);
	free_text_path(game);
	get_texture_data(game);
}


