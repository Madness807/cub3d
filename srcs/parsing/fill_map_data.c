/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/12/06 17:42:27 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	print_err_double_path(void)
{
	printf("nique ca mere");
	exit (1);
}

void	write_param(t_game *game, char *line)
{	
	if (!is_param(line))
		fill_map_param(game, copy_clean_line_map(line));
	else
	{
		print_error(ERR_INVALID_ARG_PARAM);
		exit(1);
	}
}

int	write_map(t_game *game, char *line, int mapindex)
{
	if (is_map_line(line, " \t\n"))
		print_error(ERR_EMPTY_LINE_MAP);
	else if (is_map_line(line, " 01WNSEd\n\0"))
		game->mapfile->map_tab[mapindex] = copy_clean_line_map(line);
	else if (line == NULL)
	{
		game->mapfile->map_tab[mapindex] = 0;
		printf("tagrandmere\n");
	}
	else
	{
		print_error(ERR_INVALID_ARG_MAP);
		exit (1);
	}
	return (1);
}

void	write_map_tab(t_game *game, char *argv, int mapstart)
{
	char	*line;
	int		fd;
	int		i;
	int		mapindex;

	i = 0;
	line = "";
	mapindex = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (i < mapstart)
		{
			if (line[0] != '\n')
				write_param(game, line);
		}
		if (i >= mapstart)
			mapindex += write_map(game, line, mapindex);
		free(line);
		i++;
	}
	close (fd);
}
