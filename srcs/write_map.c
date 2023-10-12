/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:47:03 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 22:56:46 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	write_map(t_slg *slg, int i, int j)
{
	while (i < slg->smy - 1)
	{	
		j = 0;
		while (j < slg->smx)
		{
			check_map_char_valid(slg, slg->tab_map[i][j]);
			if (slg->tab_map[i][j] == '0' || slg->tab_map[i][j] == 'E')
				mlx_put_image_to_window(slg->mlx_p, slg->win_p, \
					slg->floor->sprite, j * SIZE, i * SIZE);
			if (slg->tab_map[i][j] == '1')
				mlx_put_image_to_window(slg->mlx_p, slg->win_p, \
					slg->wall->sprite, j * SIZE, i * SIZE);
			if (slg->tab_map[i][j] == 'P')
				mlx_put_image_to_window(slg->mlx_p, slg->win_p, \
					slg->player->sprite, j * SIZE, i * SIZE);
			if (slg->tab_map[i][j] == 'C')
				mlx_put_image_to_window(slg->mlx_p, slg->win_p, \
					slg->item->sprite, j * SIZE, i * SIZE);
			if (slg->tab_map[i][j] == 'E')
				mlx_put_image_to_window(slg->mlx_p, slg->win_p, \
					slg->exit->sprite, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
}
