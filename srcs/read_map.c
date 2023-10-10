/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:50:30 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 20:45:40 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	read_map(t_slg *slg, char *argv)
{
	char	*line;
	int		fd;

	line = "";
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_args(slg, 6);
	while (line)
	{
		if (slg->smy != 0)
			free(line);
		line = get_next_line(fd);
		slg->smy++;
		if (!line)
			break ;
		if (line[(int)ft_strlen(line) - 1] != '\n' && \
			(((int)ft_strlen(line)) == slg->smx))
			continue ;
		check_map_rectangle(slg, line);
	}
	slg->tab_map = malloc((slg->smy) * sizeof(char *));
	if (!slg->tab_map)
		exit_game(slg);
	close(fd);
	write_tab_map(slg, fd, argv);
}

void	check_map_rectangle(t_slg *slg, char *line)
{
	if (slg->smx == 0)
		slg->smx = (int)ft_strlen(line) - 1;
	if (slg->smx != (int)ft_strlen(line) - 1)
	{
		free(line);
		error(slg, 0);
	}
}

void	write_tab_map(t_slg *slg, int fd, char *argv)
{
	int	i;

	i = 0;
	if (fd == -1)
		error_args(slg, 6);
	open(argv, O_RDONLY);
	while (i < slg->smy -1)
	{
		slg->tab_map[i] = get_next_line(fd);
		i++;
	}
	close (fd);
}
