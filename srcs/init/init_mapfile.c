/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:10:12 by efailla           #+#    #+#             */
/*   Updated: 2023/10/21 02:02:44 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_map_file(t_mapfile *mapfile)
{
	mapfile->nbr_line = 0;
	mapfile->map_tab = NULL;
	mapfile->map_int = NULL;
	mapfile->no = NULL;
	mapfile->so = NULL;
	mapfile->ea = NULL;
	mapfile->we = NULL;
	mapfile->c = NULL;
	mapfile->f = NULL;
}
