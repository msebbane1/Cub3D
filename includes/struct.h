/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:54:31 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/23 17:11:35 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_ray
{
	int		x;
	int		y;
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
	int		h;
}	t_ray;

typedef struct s_player
{
	int		move;
	double	pos_x; // pos de depart du joueur
	double	pos_y; // pos de depart du joueur
	double	dir_x; //direction initial du joueur
	double	dir_y; //direction initial du joueur
	double	plane_x; //le plan caméra du joueur
	double	plane_y; //le plan caméra du joueur
}	t_player;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

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
	int			sky[3];
	int			floor[3];
	t_img		wall[4];
	t_coord		size;
}	t_map;

typedef struct s_cub {
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*win;
	t_img		img;
}	t_cub;

#endif