/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/14 21:25:59 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>


void	init_struct_cub(t_cub *cub3d)
{
	(void)cub3d;

	//TODO - initialisation de la structure principal
	return ;
}

void	init_struct_map(t_cub *cub3d)
{
		(void)cub3d;

	//TODO - initialisation de la structure map
	return ;
}

void	init_struct_img(t_cub *cub3d)
{
	(void)cub3d;

	//TODO - initialisation de la structure image
	return ;
}

void	init_cub3d(t_cub *cub3d)
{
	init_struct_cub(cub3d);
	init_struct_map(cub3d);
	init_struct_img(cub3d);
	return ;
}