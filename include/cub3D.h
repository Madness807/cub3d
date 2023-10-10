/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:53:57 by joterret          #+#    #+#             */
/*   Updated: 2023/10/10 20:44:11 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// LIBRAIRIE
# include	"../libft/libft.h"
# include	"../mlx/mlx.h"
# include	<stdio.h>

// TOUCHE DE DEPLACEMENT
# define KEY_UP 			13
# define KEY_RIGHT			2
# define KEY_DOWN			1
# define KEY_LEFT			0
# define KEY_CLOSE_WINDOW 	53

// Sprite
# define SIZE 				32
# define FLOOR				"./sprites/floor.xpm"
# define WALL				"./sprites/wall.xpm"
# define ITEM				"./sprites/item.xpm"
# define PLAYER 			"./sprites/player.xpm"
# define EXIT				"./sprites/exit.xpm"

// STRUCTURES
typedef struct s_img
{
	void	*sprite;
	char	*path_xpm;
	int		largeur;
	int		longueur;

}t_img;

typedef struct s_slg
{
	int		ppx;
	int		ppy;
	int		pcx;
	int		pcy;
	int		pex;
	int		pey;
	int		nbr_c;
	int		nbr_taked_c;
	int		nbr_player;
	int		nbr_exit;
	int		nbr_pas;
	int		smx;
	int		smy;
	char	**tab_map;
	void	*mlx_p;
	void	*win_p;
	t_img	*wall;
	t_img	*player;
	t_img	*item;
	t_img	*floor;
	t_img	*exit;
}t_slg;

typedef struct s_chkmap
{
	int		tnbr_exit;
	int		tnbr_player;
	int		tnbr_c;
	char	**ttab_map;
}t_chkmap;

// init
void	init_var(t_slg *slg);
void	init_content(t_slg *slg, int i, int j);
void	init_sprite(t_slg *slg);
void	init_img(t_slg *slg);

// Gestion de la map
void	read_map(t_slg *slg, char *argv);
void	write_tab_map(t_slg *slg, int fd, char *argv);
void	write_map(t_slg *slg, int i, int j);

//Gestion des erreurs
void	check_map_rectangle(t_slg *slg, char *line);
void	check_map_content(t_slg *slg);
void	check_map_char_valid(t_slg *slg, char c);
void	check_map_wall(t_slg *slg);
void	pathf_init(t_slg *slg);
void	check_map_pathf(int i, int j, t_chkmap *chkmap);
void	check_map_pathres(t_slg *slg, t_chkmap *chkmap);
void	error_args(t_slg *slg, int e);
void	error_map_content(t_slg *slg, int e);
void	check_map_file(t_slg *slg, char *argv);

// Utils
void	exit_game(t_slg *slg);
void	endgame(t_slg *slg);

// Utils Moove 
void	moove_up(t_slg *slg);
void	moove_down(t_slg *slg);
void	moove_right(t_slg *slg);
void	moove_left(t_slg *slg);

// Gestion de events 
int		handle_key_event(int code, t_slg *slg);
int		handle_mouse_event(int code, t_slg *slg);
int		close_window(t_slg *slg);
void	error(t_slg *slg, int e);
void	endgame(t_slg *slg);
void	meet_c(t_slg *slg);
void	meet_e(t_slg *slg);

#endif