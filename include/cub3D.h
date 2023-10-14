/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:53:57 by joterret          #+#    #+#             */
/*   Updated: 2023/10/14 21:30:32 by joterret         ###   ########.fr       */
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
# define KEY_UP 			13
# define KEY_RIGHT			2
# define KEY_DOWN			1
# define KEY_LEFT			0
# define KEY_CLOSE_WINDOW 	53

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

typedef struct s_img
{
	void	*sprite;
	char	*path_xpm;
	int		largeur;
	int		longueur;

}t_img;

typedef struct s_map
{
	char	**map_tab;
	char 	*NO;
	char	*SO;
	char 	*WE;
	char 	*EA;
	char	*F;
	char	*C;
}t_map;


typedef struct s_cub
{
	t_map	*map;
	void	*mlx_p;
	void	*win_p;

}t_cub;

////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////

//		Init
void	init_struct(t_cub *cub3d);

//		Parsing
void	check_map_file(char *input_file);
void	read_map_file(t_cub *cub3d);
void	fill_data_struct(t_cub *cub3d);

//		Gestion de la map

//		Gestion des erreurs
void	print_error(void);

//		Utils

//		Utils Moove 

//		Gestion de events 

//		Test
void	print_struct_data(t_cub *cub3d);

#endif
