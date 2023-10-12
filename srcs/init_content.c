/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:39:09 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 22:56:56 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_var(t_slg *slg)
{
	slg->nbr_c = 0;
	slg->nbr_taked_c = 0;
	slg->nbr_pas = 0;
	slg->nbr_player = 0;
	slg->nbr_exit = 0;
	slg->smy = 0;
	slg->smx = 0;
	slg->ppx = 0;
	slg->ppy = 0;
	slg->tab_map = NULL;
	slg->player = NULL;
	slg->wall = NULL;
	slg->exit = NULL;
	slg->item = NULL;
	slg->floor = NULL;
}

void	init_content(t_slg *slg, int i, int j)
{
	while (i < slg->smy - 1)
	{
		j = 0;
		while (j < slg->smx)
		{
			if (slg->tab_map[i][j] == 'P')
			{
				slg->ppx = j;
				slg->ppy = i;
				slg->nbr_player++;
			}
			if (slg->tab_map[i][j] == 'C')
				slg->nbr_c++;
			if (slg->tab_map[i][j] == 'E')
			{
				slg->pex = i;
				slg->pey = j;
				slg->nbr_exit++;
			}
			j++;
		}
		i++;
	}
	slg->nbr_taked_c = 0;
	ft_printf("Nombre de token a rammaser %d\n", slg->nbr_c);
}

void	init_sprite(t_slg *slg)
{
	slg->floor = malloc(sizeof (t_img));
	if (!slg->floor)
		exit_game(slg);
	slg->player = malloc(sizeof (t_img));
	if (!slg->player)
		exit_game(slg);
	slg->item = malloc(sizeof (t_img));
	if (!slg->item)
		exit_game(slg);
	slg->exit = malloc(sizeof (t_img));
	if (!slg->exit)
		exit_game(slg);
	slg->wall = malloc(sizeof (t_img));
	if (!slg->wall)
		exit_game(slg);
	slg->floor->path_xpm = FLOOR;
	slg->player->path_xpm = PLAYER;
	slg->item->path_xpm = ITEM;
	slg->exit->path_xpm = EXIT;
	slg->wall->path_xpm = WALL;
}

void	init_img(t_slg *slg)
{
	slg->floor->sprite 	= mlx_xpm_file_to_image(slg->mlx_p, slg->floor->path_xpm, 	&slg->floor->longueur, 	&slg->floor->largeur);
	
	slg->player->sprite = mlx_xpm_file_to_image(slg->mlx_p, slg->player->path_xpm, 	&slg->player->longueur, 	&slg->player->largeur);
	
	slg->item->sprite 	= mlx_xpm_file_to_image(slg->mlx_p, slg->item->path_xpm, 	&slg->item->longueur, 	&slg->item->largeur);
	
	slg->exit->sprite 	= mlx_xpm_file_to_image(slg->mlx_p, slg->exit->path_xpm, 	&slg->exit->longueur, 	&slg->exit->largeur);
	
	slg->wall->sprite 	= mlx_xpm_file_to_image(slg->mlx_p, slg->wall->path_xpm, 	&slg->wall->longueur, 	&slg->wall->largeur);
}
