/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/22 01:36:27 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_struct_data(t_game *game)
{
	
	printf("\n");
	printf(YEL"GAME CONFIGURATION\n"RESET);
	printf(YEL"=======================================================\n"RESET);
	printf("SCREEN_W: \t%d\n", SCREEN_W);
	printf("SCREEN_H: \t%d\n", SCREEN_H);
	printf("CUBESIZE: \t%d\n", CUBESIZE);
	printf("FOV: \t\t%d\n", FOV);
	printf(YEL"=======================================================\n"RESET);

	printf("\n");
	printf(BLU"DATA STRUCT: mapfile\n"RESET);
	printf(BLU"=======================================================\n"RESET);
	printf("PATH NORD: \t%s\n",game->mapfile->no);
	printf("PATH SOUTH: \t%s\n",game->mapfile->so);
	printf("PATH WEST: \t%s\n",game->mapfile->we);
	printf("PATH EAST: \t%s\n",game->mapfile->ea);
	printf("COLOR FLOOR: \t%s\n",game->mapfile->f);
	printf("COLOR CEILING: \t%s\n",game->mapfile->c);
	printf("MAP\n");
	printf("-------------------------------------------------------\n");

	int i = 0;
	while(game->mapfile->map_tab[i])
	{
		printf("Line [%i]\t%s", i, game->mapfile->map_tab[i]);
		i++;
	}
	printf("\n");
	printf(BLU"=======================================================\n"RESET);
	return ;
}

