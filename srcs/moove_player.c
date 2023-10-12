/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:22:29 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 22:56:52 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	moove_up(t_slg *slg)
{
	if (slg->tab_map[slg->ppy - 1][slg->ppx] == 'E')
		meet_e(slg);
	else if (slg->tab_map[slg->ppy - 1][slg->ppx] != '1')
	{
		mlx_put_image_to_window(slg->mlx_p, slg->win_p, slg->player->sprite, \
			((slg->ppx) * SIZE), (slg->ppy -1) * SIZE);
		mlx_put_image_to_window(slg->mlx_p, slg->win_p, slg->floor->sprite, \
			(slg->ppx * SIZE), (slg->ppy * SIZE));
		slg->ppy --;
		slg->nbr_pas ++;
		ft_printf("Nombre de mouvement %i\n", slg->nbr_pas);
		if (slg->tab_map[slg->ppy][slg->ppx] == 'C')
			meet_c(slg);
	}
	return ;
}

void	moove_down(t_slg *slg)
{
	if (slg->tab_map[slg->ppy + 1][slg->ppx] == 'E')
		meet_e(slg);
	else if (slg->tab_map[slg->ppy + 1][slg->ppx] != '1')
	{
		mlx_put_image_to_window(slg->mlx_p, slg->win_p, slg->player->sprite, \
			(slg->ppx) * SIZE, (slg->ppy +1) * SIZE);
		mlx_put_image_to_window(slg->mlx_p, slg->win_p, slg->floor->sprite, \
			(slg->ppx * SIZE), (slg->ppy * SIZE));
		slg->ppy ++;
		slg->nbr_pas ++;
		ft_printf("Nombre de mouvement %i\n", slg->nbr_pas);
		if (slg->tab_map[slg->ppy][slg->ppx] == 'C')
			meet_c(slg);
	}
	return ;
}

void	moove_left(t_slg *slg)
{
	if (slg->tab_map[slg->ppy][slg->ppx - 1] == 'E')
		meet_e(slg);
	else if (slg->tab_map[slg->ppy][slg->ppx - 1] != '1')
	{
		mlx_put_image_to_window(slg->mlx_p, slg->win_p, slg->player->sprite, \
			(slg->ppx -1) * SIZE, (slg->ppy) * SIZE);
		mlx_put_image_to_window(slg->mlx_p, slg->win_p, slg->floor->sprite, \
			(slg->ppx * SIZE), (slg->ppy * SIZE));
		slg->ppx --;
		slg->nbr_pas ++;
		ft_printf("Nombre de mouvement %i\n", slg->nbr_pas);
		if (slg->tab_map[slg->ppy][slg->ppx] == 'C')
			meet_c(slg);
	}
	return ;
}

void	moove_right(t_slg *slg)
{
	if (slg->tab_map[slg->ppy][slg->ppx + 1] == 'E')
		meet_e(slg);
	else if (slg->tab_map[slg->ppy][slg->ppx + 1] != '1')
	{
		mlx_put_image_to_window(slg->mlx_p, slg->win_p, slg->player->sprite, \
			(slg->ppx +1) * SIZE, slg->ppy * SIZE);
		mlx_put_image_to_window(slg->mlx_p, slg->win_p, slg->floor->sprite, \
			(slg->ppx * SIZE), (slg->ppy * SIZE));
		slg->ppx ++;
		slg->nbr_pas ++;
		ft_printf("Nombre de mouvement %i\n", slg->nbr_pas);
		if (slg->tab_map[slg->ppy][slg->ppx] == 'C')
			meet_c(slg);
	}
	return ;
}
