/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:53:57 by joterret          #+#    #+#             */
/*   Updated: 2023/10/24 17:13:51 by efailla          ###   ########.fr       */
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
# define K_MAP			46
# define K_MOUSE		45

//presets jeu
# define SCREEN_W			1400
# define SCREEN_H			1000
# define CUBESIZE			100
# define FOV				150
//# define FOV				60

//valeurs math
# define PI					3.1415926
# define P2					PI / 2
# define P3					3 * PI / 2
//# define DR					0.0174533
# define DR					0.005

//message erreurs
# define ERR_NO_ARGS			"ERROR\nAUCUN ARGUMENT\n"
# define ERR_EXTENSION			"ERROR\nMAUVAISE EXTENSION DE FICHIER DE MAP\n"
# define ERR_MAP_WALL			"ERROR\nLA MAP N'EST PAS FERMEE PAR DES MURS\n"
# define ERR_MAP_SPRITE_PATH	"ERROR\nLA TEXTURE N'EXISTE PAS\n"
# define ERR_MAP_COLOR			"ERROR\nNUMERO DE COULEUR PLUS GRAND QUE 255\n"
# define ERR_MAP_NO_VALID_CHAR	"ERROR\nVALEUR INVALIDE DANS LA MAP\n"
# define ERR_EMPTY_LINE_MAP		"ERROR\nLigne vide dans la map\n"
# define ERR_CANT_OPEN_FILE		"ERROR\nIMPOSSIBLE D'OUVRIR LE FICHIER\n"
# define ERR_INVALID_ARG_MAP	"ERROR\nCorp étranger dans la map\n"

////////////////////////////////////////////////////////////////////////////////
// 									enum								      //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_game {
	struct s_mapfile	*mapfile;
	struct s_player		*player;
	struct s_img		*img;
	void				*mlx;
	void				*win;
	int					**map;
	int color;
	int minimap;
	int	mouse;
}t_game;

typedef struct s_img {
	void				*img;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
}t_img;

typedef struct s_player {
	double				posx;
	double				posy;
	double				deltaX;
	double				deltaY;
	double				angle;
}t_player;

typedef struct s_var {
	double				rx;
	double				ry;
	double				ra;
	double				xo;
	double				yo;
	int					dof;
	int					r;
}t_var;

typedef struct s_rgb
{
	int					hexa_color;
	int					r;
	int					g;
	int					b;
}t_rgb;

typedef struct s_mapfile
{
	char				**map_tab;
	int					nbr_line;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*c;
	int					*fd;
}t_mapfile;

////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////

//		Init
t_game	*init_game(void);
void	init_struct(t_game *game);

//		Parsing
void	check_map_file(char *input_file);
void	build_map_tab(t_game *game, char *argv);
void	write_map_tab(t_game *game, char *argv);
void	read_map_file(t_mapfile *mapfile, char *argv);
int		is_param(char *line);
int		is_map_line(char *line);
char	*copy_clean_line_map(char *line);

//		Gestion des erreurs
void    print_error(char *error);

//		Utils
double	angle_corrector(double angle);
double	return_lowest_int(double a, double b, t_game *game);
t_img 	*create_new_img(t_game *game);
int 	coord_map(double x);

//		Hooks
int		key_hook(int key, t_game *game);

//		render
void	render(t_game *game);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
int		w_colors(t_game *game, int x, int y);

//		Rays
double	ray_collision(t_game *game, t_var *var);
void	draw_rays(t_game *game, int depth, t_var *var);
void	ray_caster(t_game *game);

//		2D
void	draw_cubes(t_game *game, int x, int y, int color);
void	draw_player(t_game *game);

//		Minimap
void	draw_direction(t_game *game, int depth);

//		3D
void	draw_screen(t_game *game, t_var *var, double len, int x);
void	draw_screen_line(t_game *game, t_var *var, double len, int x);

//		Test
int		**map_alloc(t_game *game);

//		Test
void	print_struct_data(t_game *cub3d);
int		 mouse(int x, int y, t_game *game);

#endif
