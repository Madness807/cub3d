/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:04:03 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 20:45:27 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error(t_slg *slg, int e)
{
	if (e == 0)
	{
		ft_printf("\033[1;31mERROR:\033[0m ");
		ft_printf("La map n'est pas rectangle\n");
		exit(0);
	}
	if (e == 3)
	{
		ft_printf("\033[1;31mERROR:\033[0m ");
		ft_printf("Il n'existe aucun chemin valide\n");
		exit_game(slg);
	}
	if (e == 4)
	{
		ft_printf("\033[1;31mERROR:\033[0m ");
		ft_printf("Les datas de la map est/sont invalide\n");
		exit_game(slg);
	}
	return ;
}

void	error_map_content(t_slg *slg, int e)
{
	if (e == 1)
	{
		ft_printf("\033[1;31mERROR:\033[0m ");
		ft_printf("La map n'est pas entourer par des murs\n");
		exit_game(slg);
	}
	if (e == 2)
	{
		ft_printf("\033[1;31mERROR:\033[0m ");
		ft_printf("Doublon ou absence d'assets\n");
		exit_game(slg);
	}
}

void	error_args(t_slg *slg, int e)
{
	if (e == 5)
	{
		ft_printf("\033[1;31mERROR:\033[0m ");
		ft_printf("Aucun argument donner au programme.\n");
		exit_game(slg);
	}
	if (e == 6)
	{
		ft_printf("\033[1;31mERROR:\033[0m ");
		ft_printf("Le fichier n'existe pas ou n'a pas pu etre lu.\n");
		exit_game(slg);
	}
	if (e == 7)
	{
		ft_printf("\033[1;31mERROR:\033[0m ");
		ft_printf("Mauvaise extenssion de du fichier MAP.\n");
		exit_game(slg);
	}
}
