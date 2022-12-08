/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:54:31 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/08 10:50:08 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define SCREEN_W 640
# define SCREEN_H 480
# define D_W 640.0
# define D_H 480.0
# define MAP_L 24
# define MAP_H 24
# define W 13
# define A 0
# define D 2
# define S 1
# define ESC 53
# define RIGHT 124
# define LEFT 123
# define SPEED 0.08
# define R_SPEED 0.04

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	double	dist;
	int		hit;
	int		side;
	double	wallx;
	int		nb;
	int		line_h;
	double	ratio;
	double	camera;
	double	rdisdx;
	double	rdisdy;
	int		texture_x;
	int		texture_y;
}	t_ray;

typedef struct s_player
{
	int		move;
	int		nb_player;
	double	pos_x; // pos de depart du joueur
	double	pos_y; // pos de depart du joueur
	double	dir_x; //direction initial du joueur
	double	dir_y; //direction initial du joueur
	double	plane_x; //le plan caméra du joueur
	double	plane_y; //le plan caméra du joueur
	double	view;
	double	angle;
	double	speed;
	double	rotspeed;
}	t_player;

typedef struct s_img {
	void	*img;
	int		*addr;
	void	*ptr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_texture {
	void	*img;
	int		*addr;
	void	*ptr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_texture;

typedef struct s_map {
	char		**str;
	char		**rmap;
	int			index;
	int			index_spaces;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			c;
	int			f;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			color_floor;
	int			color_sky;
	int			sky[3];
	int			floor[3];
	t_texture	texture[4];
	t_coord		size;
}	t_map;

typedef struct s_cub {
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*win;
	t_img		img;
	t_ray		rays;
}	t_cub;

#endif