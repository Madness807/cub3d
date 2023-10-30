/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/30 17:11:18 by efailla          ###   ########.fr       */
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

int		line_len_c(char *line)
{
	int	i;

	i = -1;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

// char	*copy_clean_line_map(char *line)
// {
// 	int i;
// 	int	line_len;
// 	char	*ret_line;

// 	i = 0;
// 	line_len = 0;
// 	line_len = line_len_c(line);
// 	ret_line = malloc((line_len + 5) * sizeof(char));
// 	while (line[i] && line [i] != '\n')
// 	{
// 		ret_line[i] = line[i];
// 		i++;
// 	}
// 	free (line);
// 	ret_line[i] = 0;
// 	return (ret_line);
// }

int	real_map_h(t_game *game)
{
	int y;

	y = 0;
	while (game->mapfile->map_tab[y] != 0)
		y++;
	return (y);
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