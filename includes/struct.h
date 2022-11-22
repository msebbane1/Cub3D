/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:54:31 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/22 18:07:51 by msebbane         ###   ########.fr       */
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

typedef struct s_player
{
	int		counter;
	char	*count;
	int		coin;
	int		nb_player;
	int		pos_x;
	int		pos_y;
}	t_player;

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	pos;
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