/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/24 16:55:51 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_map_file(char *input_file)
{
	(void)input_file;
	return ;
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
		if (line[0] == '0' || line[0] == '1' || line[0] == ' ') 
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


