/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:53:05 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 20:45:32 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	exit_game(t_slg *slg)
{
	int	i;

	i = 0;
	if (slg->tab_map != NULL)
	{
		while (i < slg->smy - 1)
			free(slg->tab_map[i++]);
		free (slg->tab_map);
	}
	if (slg->player)
		free (slg->player);
	if (slg->item)
		free (slg->item);
	if (slg->exit)
		free (slg->exit);
	if (slg->wall)
		free (slg->wall);
	exit(EXIT_SUCCESS);
}

int	close_window(t_slg *slg)
{
	mlx_destroy_window(slg->mlx_p, slg->win_p);
	exit_game(slg);
	return (0);
}
