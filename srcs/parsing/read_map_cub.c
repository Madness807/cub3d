/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/22 02:39:19 by joterret         ###   ########.fr       */
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
	else
		return (1);

}
int	is_map_line(char *line)
{
	int i;
	int hasMapParam = 1;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			hasMapParam = 0;
		}
		
		if (!(line[i] == '0' || line[i] == '1' || line[i] == ' '|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '\n'))
		{
			return (1);
		}
		++i;
	}
	return (hasMapParam);
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
	game->mapfile->map_tab = malloc(game->mapfile->nbr_line * sizeof(char *));
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
				game->mapfile->map_tab[i] = ft_strdup(line);
				i++;
			}
			else 
			{
				printf("ERROR\n Ligne vide dans la map\n");
				exit (EXIT_FAILURE);
			}
		}
		if (is_param(line) == 0)
		{
			if (map_mode == 0)
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
			else 
			{
				printf("ERROR\n Corp etranger dans la map\n");
				exit(EXIT_FAILURE);
			}
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
