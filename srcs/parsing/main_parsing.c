/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/31 16:57:29 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int		is_map_line(char *line, char *charset)
{
	int	i;

	i = -1;
	if (!line)
	return (0);
	while (line[++i])
	{
		if (ft_strchr(charset, line[i]) == NULL)
			return (0);
	}
	return (1);
}

void	read_map_file(t_mapfile *mapfile, char *argv)
{
	char	*line;
	int		fd;

	line = "";
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE) ;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line, " WSNE01\n\0") && !is_map_line(line, " 	\n\0"))
			mapfile->map_h++;
		free(line);
	}
	mapfile->map_tab = malloc((mapfile->map_h + 2) * sizeof(char *));
	if (!mapfile->map_tab)
	{
		printf("ERROR: Malloc map tab echouer");
		exit (EXIT_FAILURE);
	}
	close (fd);
}

int		find_map_start(char *argv) // COMPTER LES \n JUSQUAU \0
{
	char	*line;
	int		fd;
	int		mapstart;
	int		i;

	line = "";
	mapstart = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE) ;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line, "	 01\n") && !is_map_line(line, " 	\n"))
		{
			mapstart = i;
			return (mapstart);
		}
		free(line);
		i++;
	}
	close (fd);
	return (0);
}

void	set_player_pos(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (game->mapfile->map_tab[++y] != 0)
	{
		while (game->mapfile->map_tab[y][++x] != 0)
		{
			if (is_player(game, x, y))
			{
				set_player_angle_pos(game, x, y);
				check_possible_path(game, x, y);
				return ;
			}
		}
		x = -1;
	}
}

void	build_map_tab(t_game *game, char *argv)
{
	int	mapstart;

	mapstart = find_map_start(argv);
	read_map_file(game->mapfile, argv);
	write_map_tab(game, argv, mapstart);
	//verif_map_spaces(game);
	only_one_player(game);
	set_player_pos(game);
	reset_map(game);
	game->mapfile->map_h = real_map_h(game) - 1;

}