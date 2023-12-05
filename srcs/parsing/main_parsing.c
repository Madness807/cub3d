/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/12/05 17:20:45 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_map_line(char *line, char *charset)
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
		//printf("%s\n", line);
		if (is_map_line(line, " WSNE01\n\0") && !is_map_line(line, " 	\n\0"))
			mapfile->map_h++;
		free(line);
	}
	mapfile->map_tab = malloc((mapfile->map_h + 4) * sizeof(char *));
	if (!mapfile->map_tab)
	{
		printf("ERROR: Malloc map tab echouer");
		exit (EXIT_FAILURE);
	}
	close (fd);
}

int		find_map_start(char *argv)
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
		//printf("%s\n", line);
		if (is_map_line(line, "	 d01\n") && !is_map_line(line, " 	\n") && !mapstart)
			mapstart = i;
		free(line);
		i++;
	}
	close (fd);
	return (mapstart);
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
	if (mapstart == 0)
		print_error(ERR_MAP_FILE);
	read_map_file(game->mapfile, argv);
	write_map_tab(game, argv, mapstart);
	//verif_map_spaces(game);
	only_one_player(game);
	set_player_pos(game);
	reset_map(game);
	game->mapfile->map_h = real_map_h(game) - 1;
	//exit(0);
}
