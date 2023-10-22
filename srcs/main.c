/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:04:27 by efailla           #+#    #+#             */
/*   Updated: 2023/10/21 20:59:37 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	**map_alloc(t_game *game)
{
	(void)game;
	int rows = 10;
    int cols = 10;

    // Allouer de la mémoire pour le tableau 2D
    int **map = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        map[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialiser le tableau 2D
    int initialMap[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Copier les valeurs de initialMap dans map
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            map[i][j] = initialMap[i][j];
        }
    }
	return (map);
}

int coord_map(double x)
{
	int n;

	n = (int)(x) / 100;
	if (n > 9)
		n = 9;
	if (n < 0)
		n = 0;
	return (n);
}
double	ray_collision(t_game *game, t_var *var)
{
	double	len;
	int mx;
	int my;

	// var->dof = 0;
	while (var->dof < 10)
	{
		mx = coord_map(var->rx);
		my = coord_map(var->ry);
		if (game->map[my][mx] == 1)
			var->dof = 10;
		else
		{
			var->rx += var->xo;
			var->ry += var->yo;
			var->dof++;
		}
	}
	len = sqrt((game->player->posx - var->rx) * ((game->player->posx - var->rx))
			+ ((game->player->posy - var->ry) * (game->player->posy - var->ry)));
	return (len);
}

int	w_colors(t_game *game, int x, int y)
{
	if (game->map[y][x] == 0)
		return (0x002D2926);
	else if (game->map[y][x] == 1)
		return (0x00D9D9D6);
	else if (game->map[y][x] == 0)
		return (0x0053565A);
	return (0);
}

int	main(int ac, char **av)
{
	t_game *game;

	if (ac < 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		exit (1);
	init_game(game);
	build_map_tab(game, av[1]);
	print_struct_data(game);
	
	//mlx_key_hook(game->win, key_hook, &game);
	//mlx_hook(game->win, 2, (1L<<0), key_hook, &game);
	//mlx_loop(game->mlx);
	return (0);
}

//NOTE - J 'AI COMMENTER TES PARTIES SI TU LES DECOMMENTE IL FAUT JUSTE 
//NOTE - COMMENTER LES MIENNES POUR QUE CA MARCHE Y A UN PETIT SOUCI AVEC UN
//NOTE - INIT ON VERRA CELA IRL