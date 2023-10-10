/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:44:54 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 20:45:30 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_key_event(int code, t_slg *slg)
{
	if (code == KEY_UP)
		moove_up(slg);
	if (code == KEY_DOWN)
		moove_down(slg);
	if (code == KEY_RIGHT)
		moove_right(slg);
	if (code == KEY_LEFT)
		moove_left(slg);
	if (code == KEY_CLOSE_WINDOW)
		exit_game(slg);
	return (0);
}

void	meet_c(t_slg *slg)
{
	if (slg->tab_map[slg->ppy][slg->ppx] == 'C')
	{
		slg->nbr_taked_c ++;
		slg->tab_map[slg->ppy][slg->ppx] = '0';
		ft_printf("Nombre de piece trouver %d,\n", slg->nbr_taked_c);
	}
	return ;
}

void	meet_e(t_slg *slg)
{
	if (slg->nbr_taked_c == slg->nbr_c)
		endgame(slg);
	return ;
}

void	endgame(t_slg *slg)
{	
	ft_printf("Bravo vous avez recuperer les items et rejoins la sortie\n");
	ft_printf("Nombre de mouvement realisé %d,\n", slg->nbr_pas);
	exit_game(slg);
}
