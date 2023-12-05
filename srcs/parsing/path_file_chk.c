/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_file_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:48:17 by joterret          #+#    #+#             */
/*   Updated: 2023/12/04 19:25:07 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int ft_check_path(char *path, char *extension, size_t suffix_length)
{
	char *res = ft_strnstr(path, extension, ft_strlen(path));

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

int chk_extension(t_game *game)
{
	char *extension;
	size_t suffix_length;
	
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
