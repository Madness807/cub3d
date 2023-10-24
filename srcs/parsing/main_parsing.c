/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/24 20:12:19 by efailla          ###   ########.fr       */
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
	int		nbr_line;

	line = "";
	nbr_line = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE) ;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line, " 01"))
			nbr_line++;
		free(line);
	}
	mapfile->map_tab = malloc(nbr_line + 1 * sizeof(char *));
	if (!mapfile->map_tab)
	{
		printf("ERROR: Malloc map tab echouer");
		exit (EXIT_FAILURE);
	}
	close (fd);
	return ;
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

void	build_map_tab(t_game *game, char *argv)
{
	int	mapstart;

	mapstart = find_map_start(argv);
	read_map_file(game->mapfile, argv);
	write_map_tab(game, argv, mapstart);
	return ;
}