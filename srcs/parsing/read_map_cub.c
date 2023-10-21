/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/21 03:06:28 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_map_file(char *input_file)
{
	(void)input_file;
	return ;
}

int	read_map_file(char *argv)
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
        if (line[0] == '0' || line[0] == '1' || line[0] == ' ') 
            nbr_line++;
        free(line);
    }
	
	close (fd);
	return (nbr_line + 1);
}


void	is_path_color(t_game *game, char *line)
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
	return ;
}

void	write_map_tab(t_game *game, char *argv)
{
	char	*line;
	int		fd;
	int		i;

	line = "";
	i = 0;
	game->mapfile->map_tab = malloc(game->mapfile->nbr_line * sizeof(char *));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1) ;
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		is_path_color(game, line);
		if (line && line[0] != '\n')
		{
			if (line[0] == 'N' || line[0] == 'W' || line[0] == 'S' || line[0] == 'E' || line[0] == 'F' || line[0] == 'C')
			{
				printf("ERREUR:\nCorp etranger dans la map");
				exit (EXIT_FAILURE);
			}
			game->mapfile->map_tab[i] = ft_strdup(line);
			i++;
		}
		else if (line && line[0] == '\n')
			continue;
		else
		{
			printf(ERR_MAP_NO_VALID_CHAR);
			exit (1);
		}
		free (line);
	}
	game->mapfile->map_tab[i] = 0;
	close (fd);
	return ;
}

void	build_map_tab(t_game *game, char *argv)
{
	t_mapfile *mapfile;

	mapfile = game->mapfile;
	mapfile->nbr_line = read_map_file(argv);
	write_map_tab(game, argv);
	return ;
}

//TODO - LA PARTIE MAP NE DOIT PAS AVOIR DE DE LIGNE VIDE 
//TODO - REFACTORISER LA FONCTION WRITE MAP 
//TODO - FAIRE UNE FONCTION QUI PERMET DE RENTRER EN MODE MAP POUR NE PARCOURIR QUE LA MAP ET EN CAS DE CORP 


