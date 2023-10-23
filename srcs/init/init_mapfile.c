/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:10:12 by efailla           #+#    #+#             */
/*   Updated: 2023/10/22 19:45:30 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_trgb(t_rgb *rgb)
{
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
}
void	init_map_file(t_mapfile *mapfile)
{
	t_rgb *rgb_celling;
	t_rgb *rgb_floor;

	rgb_celling = malloc (sizeof(t_rgb));
	rgb_floor = malloc (sizeof(t_rgb));
	init_trgb(rgb_celling);
	init_trgb(rgb_floor);
	mapfile->nbr_line = 0;
	mapfile->map_tab = NULL;
	mapfile->no = NULL;
	mapfile->so = NULL;
	mapfile->ea = NULL;
	mapfile->we = NULL;
	mapfile->c = NULL;
	mapfile->f = NULL;

}
