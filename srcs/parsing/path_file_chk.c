/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_file_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:48:17 by joterret          #+#    #+#             */
/*   Updated: 2023/12/06 17:35:32 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	chk_double_path(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 && game->mapfile->no != NULL)
		print_err_double_path();
	else if (ft_strncmp(line, "WE", 2) == 0 && game->mapfile->we != NULL)
		print_err_double_path();
	else if (ft_strncmp(line, "SO", 2) == 0 && game->mapfile->so != NULL)
		print_err_double_path();
	else if (ft_strncmp(line, "EA", 2) == 0 && game->mapfile->ea != NULL)
		print_err_double_path();
	else if (ft_strncmp(line, "F", 1) == 0 && game->mapfile->f >= 0)
		print_err_double_path();
	else if (ft_strncmp(line, "C", 1) == 0 && game->mapfile->c >= 0)
		print_err_double_path();
	return (0);
}

void	fill_map_param(t_game *game, char *line)
{
	if (chk_double_path(game, line) == 0 && ft_strncmp(line, "NO", 2) == 0)
		game->mapfile->no = ft_strtrim(line, "NO ");
	else if (chk_double_path(game, line) == 0 && ft_strncmp(line, "WE", 2) == 0)
		game->mapfile->we = ft_strtrim(line, "WE ");
	else if (chk_double_path(game, line) == 0 && ft_strncmp(line, "SO", 2) == 0)
		game->mapfile->so = ft_strtrim(line, "SO ");
	else if (chk_double_path(game, line) == 0 && ft_strncmp(line, "EA", 2) == 0)
		game->mapfile->ea = ft_strtrim(line, "EA ");
	else if (chk_double_path(game, line) == 0 && ft_strncmp(line, "F", 1) == 0)
		game->mapfile->f = str_to_color(ft_strtrim(line, "F "));
	else if (chk_double_path(game, line) == 0 && ft_strncmp(line, "C", 1) == 0)
		game->mapfile->c = str_to_color(ft_strtrim(line, "C "));
}

int	ft_check_path(char *path, char *extension, size_t suffix_length)
{
	char	*res;

	res = ft_strnstr(path, extension, ft_strlen(path));
	if (res == NULL || (res - path) + strlen(extension) != strlen(path)
		|| ft_strncmp(res, extension, suffix_length) != 0)
	{
		print_error(ERR_MAP_XPM_BAD_EXT);
		return (1);
	}
	if (access(path, F_OK) != 0)
	{
		print_error(ERR_MAP_NO_FILE_ACCESS);
		return (1);
	}
	if (access(path, R_OK) != 0)
	{
		print_error(ERR_MAP_NO_XPM_ACCESS);
		return (1);
	}
	return (0);
}

int	chk_extension(t_game *game)
{
	char	*extension;
	size_t	suffix_length;

	extension = ".xpm";
	suffix_length = strlen(extension);
	if (ft_check_path(game->mapfile->no, extension, suffix_length) == 1)
		exit (1);
	if (ft_check_path(game->mapfile->so, extension, suffix_length) == 1)
		exit (1);
	if (ft_check_path(game->mapfile->we, extension, suffix_length) == 1)
		exit (1);
	if (ft_check_path(game->mapfile->ea, extension, suffix_length) == 1)
		exit (1);
	return (0);
}
