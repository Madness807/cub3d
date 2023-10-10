/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:53:52 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 20:45:44 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_slg		slg;

	bzero(&slg, sizeof(t_slg));
	(void)argc;
	if (!argv[1])
		error_args(&slg, 5);
	check_map_file(&slg, argv[1]);
	init_var(&slg);
	read_map(&slg, argv[1]);
	init_sprite(&slg);
	slg.mlx_p = mlx_init();
	init_img(&slg);
	slg.win_p = mlx_new_window(slg.mlx_p, slg.smx * SIZE, \
	(slg.smy - 1) * SIZE, "Cyber Solong");
	init_content(&slg, 0, 0);
	check_map_content(&slg);
	check_map_wall(&slg);
	write_map(&slg, 0, 0);
	pathf_init(&slg);
	mlx_hook(slg.win_p, 2, 0, handle_key_event, &slg);
	mlx_hook(slg.win_p, 17, 0, close_window, &slg);
	mlx_loop(slg.mlx_p);
	return (0);
}
