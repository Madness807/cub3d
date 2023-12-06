/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:04:27 by efailla           #+#    #+#             */
/*   Updated: 2023/12/06 17:30:35 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_scandale(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), key_hook, game);
	mlx_hook(game->win, 6, (1L << 6), mouse, game);
	mlx_hook(game->win, 3, 3, sprint_release, game);
	mlx_hook(game->win, 17, 0, hook_exit, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		print_error(ERR_NO_ARGS);
		return (1);
	}
	ft_check_argv(av[1]);
	game = init_game();
	build_map_tab(game, av[1]);
	print_struct_data(game);
	chk_extension(game);
	load_textures(game);
	render(game);
	ft_scandale(game);
	return (0);
}
