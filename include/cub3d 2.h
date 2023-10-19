/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d 2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efailla <efailla@42Lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:04:48 by efailla           #+#    #+#             */
/*   Updated: 2023/10/19 06:50:39 by efailla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
//# include "Mlx/mlx.h"
//# include "libft/libft.h"

#define K_ESC 		53
#define K_UP		13
#define K_DOWN		1
#define K_LEFT		0
#define K_RIGHT		2

# define SCREEN_W 1000
# define SCREEN_H 1000
# define CUBESIZE 100
# define PI 3.1415926
# define P2 PI / 2
# define P3 3 * PI / 2
# define DR 0.0174533
# define FOV 60

typedef struct s_game {
	void	*mlx;
	void	*win;
	struct s_player *player;
	struct s_img *img;
	int		**map;
	int color;
}				t_game;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct s_player {
	double	posx;
	double	posy;
	double	deltaX;
	double	deltaY;
	double	angle;
}				t_player;
typedef struct s_var {
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	int		dof;
	int		r;
}				t_var;

int	**map_alloc(t_game *game);

/*INIT*/
t_game *init_game(void);

/*HOOKS*/
int	key_hook(int key, t_game *game);

/*RENDER*/
void	render(t_game *game);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
/*RAYS*/
double	ray_collision(t_game *game, t_var *var, double aTan);
void	draw_rays(t_game *game, int depth, t_var *var);
void	ray_caster(t_game *game);
/*3D render*/
void	draw_screen(t_game *game, t_var *var, double len, int x);
/*UTILS*/
double	angle_corrector(double angle);
double	return_lowest_int(double a, double b, t_game *game);
t_img *create_new_img(t_game *game);
void draw_cubes(t_game *game,int x, int y, int color);
void	player(t_game *game);
int	w_colors(t_game *game, int x, int y);
void	draw_player(t_game *game);
# endif