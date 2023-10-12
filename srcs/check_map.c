/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:59:03 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 22:57:05 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	check_map_file(t_slg *slg, char *argv)
{
	int	len;

	len = ft_strlen(argv) - 1;
	if (argv[len] != 'r')
		error_args(slg, 7);
	if (argv[len - 1] != 'e')
		error_args(slg, 7);
	if (argv[len - 2] != 'b')
		error_args(slg, 7);
	if (argv[len -3] != '.')
		error_args(slg, 7);
	return ;
}

void	check_map_wall(t_slg *slg)
{
	int	i;
	int	j;

	i = 0;
	while (i < slg->smy - 2)
	{	
		j = 0;
		while (j < slg->smx - 1)
		{
			if (slg->tab_map[0][j] != '1')
				error_map_content(slg, 1);
			if (slg->tab_map[slg->smy - 2][j] != '1')
				error_map_content(slg, 1);
			if (slg->tab_map[i][0] != '1')
				error_map_content(slg, 1);
			if (slg->tab_map[i][slg->smx - 1] != '1')
				error_map_content(slg, 1);
			j++;
		}
		i++;
	}
}

void	check_map_content(t_slg *slg)
{
	if (slg->nbr_c < 1)
		error_map_content(slg, 2);
	if (slg->nbr_exit != 1)
		error_map_content(slg, 2);
	if (slg->nbr_player != 1)
		error_map_content(slg, 2);
	return ;
}

void	check_map_char_valid(t_slg *slg, char c)
{
	if (!ft_strchr("01EPC", c))
		error(slg, 4);
	return ;
}
