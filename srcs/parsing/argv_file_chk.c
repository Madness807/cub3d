/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_file_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:57:23 by joterret          #+#    #+#             */
/*   Updated: 2023/12/05 16:06:45 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int ft_check_argv(char *argv)
{
    char *extension;
    char *res;
    size_t  suffix_lenght;

    extension = ".cub";
    suffix_lenght = ft_strlen(extension);

	res = ft_strnstr(argv, extension, ft_strlen(argv));

	if (res == NULL || (res - argv) + strlen(extension) != strlen(argv) 
		|| ft_strncmp(res, extension, suffix_lenght) != 0)
	{
		print_error(ERR_MAP_CUB_BAD_EXT);
		exit (1);
	}
	if (access(argv, F_OK) != 0)
	{
		print_error(ERR_MAP_NO_FILE_ACCESS);
		exit (1);
	}
	if (access(argv, R_OK) != 0)
	{
		print_error(ERR_MAP_NO_XPM_ACCESS);
		exit (1);
	}
	return (0);
}