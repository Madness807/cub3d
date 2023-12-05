/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:04:27 by efailla           #+#    #+#             */
/*   Updated: 2023/12/05 16:11:35 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void stock_x_tex(t_var *var, t_game *game, int len, int x)
{
	(void)game;
	if (x)
	{
		if (var->ra > PI)
			var->line->x = ((int)var->rx % CUBESIZE);
		else
			var->line->x = (CUBESIZE - ((int)var->rx % CUBESIZE));
	}
	else if (!x && len < var->len)
	{
		if (var->ra < P2 || var->ra > P3)
			var->line->x = ((int)var->ry % CUBESIZE); 
		else
			var->line->x = (CUBESIZE - ((int)var->ry % CUBESIZE));
	}
}

double	ray_collision(t_game *game, t_var *var, int x)
{
	double	len;
	int		mx;
	int		my;

	var->line->side = -1;
	while (var->dof < 50)
	{
		my = coord_mapy(var->ry, game->mapfile->map_h);
		mx = coord_mapx(game, var->rx, my);
		if (game->mapfile->map_tab[my][mx] == '1')
			var->dof = 50;
		else if (game->mapfile->map_tab[my][mx] == 'd')
		{
			var->dof = 50;
			var->line->side = DOOR;
		}
		else
		{
			var->rx += var->xo;
			var->ry += var->yo;
			var->dof++;
		}
	}
	len = sqrt((game->player->posx - var->rx) * ((game->player->posx - var->rx))
			+ ((game->player->posy - var->ry) * (game->player->posy - var->ry)));
	stock_x_tex(var, game, len, x);
	return (len);
}

int	params(int key, t_game *game)
{
	if (key == K_OPEN)
		open_door(game);
	if (game->minimap == 0 && key == K_MAP)
		game->minimap = 1;
	else if (game->minimap == 1 && key == K_MAP)
		game->minimap = 0;
	if (game->mouse == 0 && key == K_MOUSE)
	{
		game->mouse = 1;
		mlx_mouse_hide();
	}
	else if (game->mouse == 1 && key == K_MOUSE)
	{
		game->mouse = 0;
		mlx_mouse_show();
	}
	render(game);
	return (0);
}

int	w_colors(t_game *game, int x, int y)
{
	if (game->mapfile->map_tab[y][x] == '0')
		return (0x002D2926);
	else if (game->mapfile->map_tab[y][x] == '1')
		return (0x00D9D9D6);
	else if (game->mapfile->map_tab[y][x] == 'd')
		return (0x00FF0000);
	else if (game->mapfile->map_tab[y][x] == 'D')
		return (0x0000FF00);
	return (0);
}

void	ft_scandale(t_game *game)
{
	//mlx_key_hook(game->win, params, game);
	mlx_hook(game->win, 2, (1L<<0), key_hook, game);
	mlx_hook(game->win, 6, (1L << 6), mouse, game);
	mlx_hook(game->win, 3, 3, sprint_release, game);
	mlx_hook(game->win, 17, 0, hook_exit, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game *game;
	//sleep(10);
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
