/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:33:36 by efailla           #+#    #+#             */
/*   Updated: 2023/12/04 14:35:27 by joterret         ###   ########.fr       */
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

    tablen = 0;
    while (str[tablen] != NULL)
        tablen++;
    if (tablen == 3)
        return (1);
    else
    {
        print_error(ERR_MAP_NUMER_OF_COLOR);
        exit (1);
    }
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
    chk_rgb_tab_len(rgb);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    check_value_color(r);
    check_value_color(g);
    check_value_color(b);
    free(rgb[0]);
    free(rgb[1]);
    free(rgb[2]);
    free(str);
    free(rgb);
    r *= 65536;
    g *= 256;
    return (r + g + b);
}