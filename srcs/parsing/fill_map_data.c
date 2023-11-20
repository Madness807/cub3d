/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/11/20 11:37:47 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	fill_map_param(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		game->mapfile->no = ft_strtrim(line, "NO ");
	else if (ft_strncmp(line, "WE", 2) == 0)
		game->mapfile->we = ft_strtrim(line, "WE ");
	else if (ft_strncmp(line, "SO", 2) == 0)
		game->mapfile->so = ft_strtrim(line, "SO ");
	else if (ft_strncmp(line, "EA", 2) == 0)
		game->mapfile->ea = ft_strtrim(line, "EA ");
	else if (ft_strncmp(line, "F", 1) == 0)
		game->mapfile->f = str_to_color(ft_strtrim(line, "F "));
	else if (ft_strncmp(line, "C", 1) == 0)
		game->mapfile->c = str_to_color(ft_strtrim(line, "C "));
}

void	write_param(t_game *game, char *line)
{
	if (!is_param(line))
		fill_map_param(game, copy_clean_line_map(line));
	else
		print_error(ERR_INVALID_ARG_PARAM);
	
}

void	write_map(t_game *game, char *line, int mapindex)
{
	if (is_map_line(line, " 	\n"))
		print_error(ERR_EMPTY_LINE_MAP);
	else if (is_map_line(line, " 01WNSEd\n\0"))
		game->mapfile->map_tab[mapindex] = copy_clean_line_map(line);
	else if (line == NULL)
		game->mapfile->map_tab[mapindex] = 0;
	else
	{
		print_error(ERR_INVALID_ARG_MAP);
		exit (1);
	}
}

void	write_map_tab(t_game *game, char *argv, int mapstart)
{
	char	*line;
	int		fd;
	int		i;
	int		mapindex;

	line = "";
	i = 0;
	mapindex = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (i < mapstart)
		{
			write_param(game, line);
			free(line);
		}
		else if (i >= mapstart)
		{
			write_map(game, line, mapindex);
			mapindex++;
			free(line);
		}
		//free(line);
		i++;
	}
	close (fd);
}
