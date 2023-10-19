/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/19 18:46:26 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_map_file(char *input_file)//TODO - verif extension
{
	(void)input_file;
	return ;
}

int		read_map_file(char *argv)
{
	char	*line;
	int		fd;
	int 	nbr_line;

	line = "";
	nbr_line = 0;
	fd = open(argv, O_RDONLY);
	//if (fd == -1)
	//	printf(err_cant_open_file);
	while (line)
	{
		line = get_next_line(fd);
		nbr_line++;
	}
	close (fd);
	return (nbr_line);
}

void	write_map_tab(t_game *game, char *argv)
{

	char	*line;
	int		fd;
	int 	i;

	line = "";
	i = 0;
	game->mapfile->map_tab = malloc(game->mapfile->nbr_line * sizeof(char*));

	fd = open(argv, O_RDONLY);
	// if (fd == -1)
	// 	printf(err_cant_open_file);
		
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		int line_len = ft_strlen(line) -1;
		game->mapfile->map_tab[i] = malloc(line_len * sizeof(char));
		game->mapfile->map_tab[i] = line;
		i++;
	}
	game->mapfile->map_tab[i] = 0;

	
	i = 0;
	while (game->mapfile->map_tab[i])
	{
		printf("%s",game->mapfile->map_tab[i]);
		i++;
	}

	close (fd);
	return ;
}

void	build_map_tab(t_game *game, char *argv)
{
	printf("%s\n", argv);



	game->mapfile->nbr_line = read_map_file(argv);
	write_map_tab(game, argv);
	return ;
}

