/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/23 14:10:52 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/*//TODO - split et atoi
void	fill_color(t_game *game, char *line)
{
	char *raw_color_line;

	if (ft_strncmp(line, "F", 1) == 0)
	{
		game->mapfile->color_floor->r = 0;
		game->mapfile->color_floor->g = 0; 
		game->mapfile->color_floor->b = 0;
		return ;
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
		game->mapfile->color_celling->r = 0;
		game->mapfile->color_celling->g = 0;
		game->mapfile->color_celling->b = 0;
		return ;
	}
}
*/

void	fill_map_param(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		game->mapfile->no = ft_strtrim(line, "NO ");
	else if (ft_strncmp(line, "WE", 2) == 0)
		game->mapfile->we = ft_strtrim(line, "WE ");
	else if (ft_strncmp(line, "SO", 2) == 0)
		game->mapfile->so = ft_strtrim(line, "SO ");
	else if (ft_strncmp(line, "EA", 2) == 0)
		game->mapfile->ea= ft_strtrim(line, "EA ");
	else if (ft_strncmp(line, "F", 1) == 0)
		game->mapfile->f= ft_strtrim(line, "F ");
	else if (ft_strncmp(line, "C", 1) == 0)
		game->mapfile->c= ft_strtrim(line, "C ");

}

void	write_map_tab(t_game *game, char *argv)
{
	char	*line;
	int		fd;
	int		i;
	int		map_mode;

	line = "";
	i = 0;
	map_mode = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1) ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\n')
			continue ;
		if (is_map_line(line) == 0)
		{
			map_mode = 1;
			if (line[0] != '\n')
			{		
				game->mapfile->map_tab[i] = copy_clean_line_map(line);
				i++;
			}
			else 
				print_error(ERR_EMPTY_LINE_MAP);
		}
		if (is_param(line) == 0)
		{
			if (map_mode == 0)
				fill_map_param(game, line);
			else 
				print_error(ERR_INVALID_ARG_MAP);
		}
		free (line);
	}
	game->mapfile->map_tab[i] = 0;
	close (fd);
	return ;
}
