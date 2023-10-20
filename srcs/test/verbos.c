/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/20 05:04:25 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_struct_data(t_game *game)
{
	int i;

	i = 0;
	printf("\n");
	printf(BLU"DATA STRUCT: mapfile\n"RESET);
	printf(BLU"=======================================================\n"RESET);
	printf("PATH NORD: \t%s",game->mapfile->no);
	printf("PATH SOUTH: \t%s",game->mapfile->so);
	printf("PATH WEST: \t%s",game->mapfile->we);
	printf("PATH EAST: \t%s\n",game->mapfile->ea);
	printf("PATH FLOOR: \t%s",game->mapfile->f);
	printf("PATH CEILING: \t%s\n",game->mapfile->c);
	printf("MAP:\n");

	while(game->mapfile->map_tab[i])
	{
		printf("%s",game->mapfile->map_tab[i]);
		i++;
	}
	printf("\n");
	printf(BLU"=======================================================\n"RESET);
	return ;
}

