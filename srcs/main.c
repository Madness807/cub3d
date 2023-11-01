/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:04:27 by efailla           #+#    #+#             */
/*   Updated: 2023/11/01 19:41:04 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	**map_alloc(t_game *game)
// {
// 	(void)game;
// 	int rows = 10;
//     int cols = 10;

//     // Allouer de la mémoire pour le tableau 2D
//     int **map = (int **)malloc(rows * sizeof(int *));
//     for (int i = 0; i < rows; i++) {
//         map[i] = (int *)malloc(cols * sizeof(int));
//     }

//     // Initialiser le tableau 2D
//     int initialMap[10][10] = {
//         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//         {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
//         {1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 1, 0, 0, 1, 0, 1},
//         {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
//         {1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
//         {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
//         {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
//         {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
//         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//     };

//     // Copier les valeurs de initialMap dans map
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             map[i][j] = initialMap[i][j];
//         }
//     }
// 	return (map);
// }


double	ray_collision(t_game *game, t_var *var)
{
	double	len;
	int mx;
	int my;

	// var->dof = 0;
	while (var->dof < 50)
	{
		my = coord_mapy(var->ry, game->mapfile->map_h);
		mx = coord_mapx(game, var->rx, my);
		// printf("coord x : %d\n", mx);
		// printf("coord y : %d\n\n", my);
		if (game->mapfile->map_tab[my][mx] == '1')
			var->dof = 50;
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

int	params(int key, t_game *game)
{
	if (game->minimap == 0 && key == K_MAP)
		game->minimap = 1;
	else if (game->minimap == 1 && key == K_MAP)
		game->minimap = 0;
	if (game->mouse == 0 && key == K_MOUSE)
		game->mouse = 1;
	else if (game->mouse == 1 && key == K_MOUSE)
		game->mouse = 0;
	render(game);
	return (0);
}

int	w_colors(t_game *game, int x, int y)
{
	if (game->mapfile->map_tab[y][x] == '0')
		return (0x002D2926);
	else if (game->mapfile->map_tab[y][x] == '1')
		return (0x00D9D9D6);
	else if (game->mapfile->map_tab[y][x] == 'W')
		return (0x0053565A);
	return (0);
}

void	ft_scandale(t_game *game)
{
	mlx_key_hook(game->win, params, game);
	mlx_hook(game->win, 2, (1L<<0), key_hook, game);
	mlx_hook(game->win, 6, (1L << 6), mouse, game);
	mlx_mouse_hide();
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game *game;

	if (ac < 2)
		return (1);
	game = init_game();
	build_map_tab(game, av[1]);
	print_struct_data(game);
	//printf("maph : %d\n\n", game->mapfile->map_h);
	render(game);
	// printf("couleur C : %s\n", game->mapfile->c);
	// printf("couleur F : %s\n\n", game->mapfile->f);
	printf("maph : %X\n\n", game->mapfile->f);
	printf("maph : %X\n\n", game->mapfile->c);
	ft_scandale(game);

	return (0);
}
