/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:53:57 by joterret          #+#    #+#             */
/*   Updated: 2023/10/19 17:57:37 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

////////////////////////////////////////////////////////////////////////////////
// 									Librairies							      //
////////////////////////////////////////////////////////////////////////////////

# include	"../lib/libft/libft.h"
# include	"../lib/mlx/mlx.h"
# include	<stdio.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<string.h>
# include	<math.h>

////////////////////////////////////////////////////////////////////////////////
// 									DEFINE								      //
////////////////////////////////////////////////////////////////////////////////

//couleur pour les printf
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define RESET "\x1B[0m"

//key binding
# define K_UP 			13
# define K_RIGHT		2
# define K_DOWN			1
# define K_LEFT			0
# define K_ESC			53

//presets jeu
# define SCREEN_W			1000
# define SCREEN_H			1000
# define CUBESIZE			100
# define FOV				60

//valeurs math
# define PI					3.1415926
# define P2					PI / 2
# define P3					3 * PI / 2
# define DR					0.0174533

//message erreurs
# define err_extension			"Error\nMauvaise extension de fichier de map"
# define err_map_wall			"Error\nLa map n'est pas fermee par des murs"
# define err_map_sprite_path	"Error\nLa texture n'existe pas"
# define err_map_color			"Error\nNumero de couleur plus grand que 255"
# define err_map_no_valid_char	"Error\nValeur invalide dans la map"

////////////////////////////////////////////////////////////////////////////////
// 									enum								      //
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_game {
	void				*mlx;
	void				*win;
	struct s_player 	*player;
	struct s_img 		*img;
	int					**map;
	struct s_mapfile	*mapfile;
	int color;
}t_game;

typedef struct s_img {
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}t_img;

typedef struct s_player {
	double			posx;
	double			posy;
	double			deltaX;
	double			deltaY;
	double			angle;
}t_player;

typedef struct s_var {
	double			rx;
	double			ry;
	double			ra;
	double			xo;
	double			yo;
	int				dof;
	int				r;
}t_var;

typedef struct s_mapfile
{
	int		nbr_line;
	char	**map_tab;
	char 	*NO;
	char	*SO;
	char 	*WE;
	char 	*EA;
	char	*F;
	char	*C;
}t_mapfile;

////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////

//		Init
t_game 	*init_game(void);
void	init_struct(t_game *game);

//		Parsing
void	check_map_file(char *input_file);
void	build_map_tab(t_game *game, char *argv);
void	write_map_tab(t_game *game, char *argv);
int		read_map_file(char *argv);

//		Gestion de la map

//		Gestion des erreurs
void	print_error(void);

//		Utils
double	angle_corrector(double angle);
double	return_lowest_int(double a, double b, t_game *game);
t_img 	*create_new_img(t_game *game);

//		Hooks
int		key_hook(int key, t_game *game);

//		render
void	render(t_game *game);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
int	w_colors(t_game *game, int x, int y);

//		Rays
double	ray_collision(t_game *game, t_var *var);
void	draw_rays(t_game *game, int depth, t_var *var);
void	ray_caster(t_game *game);

//		2D
void 	draw_cubes(t_game *game,int x, int y, int color);
void	draw_player(t_game *game);

//		3D
void	draw_screen(t_game *game, t_var *var, double len, int x);
void	draw_screen_line(t_game *game, t_var *var, double len, int x);

//		Test
int		**map_alloc(t_game *game);

//		Test
void	print_struct_data(t_game *cub3d);

#endif
