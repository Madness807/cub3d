/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:33:36 by efailla           #+#    #+#             */
/*   Updated: 2023/11/20 11:11:00 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int check_value_color(int color)
{
    if (color < 0 || color > 255)
    {
        print_error(ERR_MAP_COLOR_RANGE);
        exit(1);
    }
    return (0);
}

int chk_rgb_tab_len(char **str)
{
    size_t tablen;

    tablen = ft_strlen(*str);
    /*
    if (tablen > 2)
    {
        print_error(ERR_MAP_NUMER_OF_COLOR);
        exit (1);
    }
    */
    return (0);
}

int str_to_color(char *str)
{
    char    **rgb;
    int     r;
    int     g;
    int     b;

    rgb = ft_split(str, ',');
    chk_rgb_tab_len(rgb);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    check_value_color(r);
    check_value_color(g);
    check_value_color(b);
    free(str);
    free(rgb);
    r *= 65536;
    g *= 256;
    return (r + g + b);
}

// int	str_to_color(char *str)
// {
// 	char	**rgb;
// 	int		r;
// 	int		g;
// 	int		b;

// 	rgb = ft_split(str, ',');
// 	r = ft_atoi(rgb[0]);
// 	g = ft_atoi(rgb[1]);
// 	b = ft_atoi(rgb[2]);
// 	free(str);
// 	free(rgb);
// 	r *= 65536;
// 	g *= 256;
// 	return (r + g + b);
// }