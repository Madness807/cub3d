/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_Pathf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:47:32 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 20:45:23 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	pathf_init(t_slg *slg)
{
	t_chkmap	chkmap;
	int			i;

	i = 0;
	chkmap.tnbr_c = slg->nbr_c;
	chkmap.tnbr_exit = slg->nbr_exit;
	chkmap.tnbr_player = slg->nbr_player;
	chkmap.ttab_map = malloc((slg->smy + 1) * sizeof(char *));
	if (!chkmap.ttab_map)
		exit_game(slg);
	while (i < slg->smy - 1)
	{
		chkmap.ttab_map[i] = ft_strdup(slg->tab_map[i]);
		i++;
	}
	check_map_pathf(slg->ppy, slg->ppx, &chkmap);
	check_map_pathres(slg, &chkmap);
	return ;
}

void	check_map_pathf(int i, int j, t_chkmap *chkmap)
{
	if (chkmap->ttab_map[i][j] == '1' || chkmap->ttab_map[i][j] == 'V')
		return ;
	if (chkmap->ttab_map[i][j] == 'P')
		chkmap->tnbr_player--;
	if (chkmap->ttab_map[i][j] == 'C')
		chkmap->tnbr_c--;
	if (chkmap->ttab_map[i][j] == 'E')
	{
		chkmap->tnbr_exit--;
		chkmap->ttab_map[i][j] = 'V';
		return ;
	}
	chkmap->ttab_map[i][j] = 'V';
	check_map_pathf(i, j + 1, chkmap);
	check_map_pathf(i, j - 1, chkmap);
	check_map_pathf(i + 1, j, chkmap);
	check_map_pathf(i - 1, j, chkmap);
	return ;
}

void	check_map_pathres(t_slg *slg, t_chkmap *chkmap)
{	
	int	i;

	if (chkmap->tnbr_c != 0)
		error(slg, 3);
	if (chkmap->tnbr_exit != 0)
		error(slg, 3);
	if (chkmap->tnbr_player != 0)
		error(slg, 3);
	i = 0;
	while (i < slg->smy - 1)
		free(chkmap->ttab_map[i++]);
	free (chkmap->ttab_map);
	return ;
}
