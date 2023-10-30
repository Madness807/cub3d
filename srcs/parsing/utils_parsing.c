/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/30 18:42:27 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_param(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "F", 1) == 0)
		return (0);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (0);
	else if (ft_strncmp(line, "\n", 1) == 0)
		return (0);
	else
		return (1);
}

int	real_map_h(t_game *game)
{
	int y;

	y = 0;
	while (game->mapfile->map_tab[y] != 0)
		y++;
	return (y);
}

// void	possible_space(t_game *game, int x, int y)
// {
// 	if (x != 0)
// 	{
// 		if (game->mapfile->map_tab[y][x + 1] == '1')
// 			print_error("Map is not valid, space is not surrounded by walls\n");
// 		if (game->mapfile->map_tab[y][x - 1] != '1')
// 			print_error("Map is not valid, space is not surrounded by walls\n");
// 	}
// 	if (y != 0)
// 	{
// 		if (game->mapfile->map_tab[y + 1][x] != '1')
// 			print_error("Map is not valid, space is not surrounded by walls\n");
// 		if (game->mapfile->map_tab[y - 1][x] != '1')
// 			print_error("Map is not valid, space is not surrounded by walls\n");
// 	}
// }

// void	verif_map_spaces(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	x = -1;
// 	y = -1;
// 	while (game->mapfile->map_tab[++y] != 0)
// 	{
// 		while (game->mapfile->map_tab[y][++x] != 0)
// 		{
// 			if (game->mapfile->map_tab[y][x] == '0')
// 				possible_space(game, x, y);
// 		}
// 		x = -1;
// 	}
// }

void	set_player_angle_pos(t_game *game, int x, int y)
{
	game->player->posx = x * 100 + 50;
	game->player->posy = y * 100 + 50;
	if (game->mapfile->map_tab[y][x] == 'W')
		game->player->angle = PI;
	else if (game->mapfile->map_tab[y][x] == 'N')
		game->player->angle = PI + PI /2;
	else if (game->mapfile->map_tab[y][x] == 'S')
		game->player->angle = PI / 2;
	else if (game->mapfile->map_tab[y][x] == 'E')
		game->player->angle = 0;
}

char	*copy_clean_line_map(char *line)
{
	int i;
	int	line_len;
	char	*ret_line;

	i = 0;
	line_len = 0;
	line_len = ft_strlen(line);
	ret_line = malloc((line_len) * sizeof(char) + 10);
	while (line[i])
	{
		
		if (line[i] != '\n')
		{	
			ret_line[i] = line[i];
		}
		else if (line[i] == '\n')
		{			
			ret_line[i] = '\0';
			return (ret_line);
		}
		i++;
	}
	free(line);
	ret_line[i] = 0;
	return (ret_line);
}