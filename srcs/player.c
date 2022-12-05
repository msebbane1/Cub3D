/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:53 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/05 17:31:09 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	view_north_south(t_cub *cub, char map)
{
	if (map == 'S')
	{
		cub->player.dir_x = 0.;
		cub->player.dir_y = 1;
		cub->player.plane_x = -0.66;
		cub->player.plane_y = 0.;
	}
	if (map == 'N')
	{
		cub->player.dir_x = 0.;
		cub->player.dir_y = -1;
		cub->player.plane_x = 0.66;
		cub->player.plane_y = 0.;
	}
}

void	init_angle_view(t_cub *cub, char map)
{
	if (map == 'W')
	{
		cub->player.dir_x = -1;
		cub->player.dir_y = 0.;
		cub->player.plane_x = 0.;
		cub->player.plane_y = -0.66;
	}
	if (map == 'E')
	{
		cub->player.dir_x = 1;
		cub->player.dir_y = 0.;
		cub->player.plane_x = 0.;
		cub->player.plane_y = 0.66;
	}
	view_north_south(cub, map);
}

void	position_player(t_cub *cub)
{
	int		c;
	int		l;
	int		g;

	l = cub->map.index_spaces;
	g = 0;
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c])
		{
			if (cub->map.str[l][c] == 'N' || cub->map.str[l][c] == 'S'
				|| cub->map.str[l][c] == 'W' || cub->map.str[l][c] == 'E')
			{
				cub->player.pos_x = c + 0.5;
				cub->player.pos_y = g + 0.5;
				init_angle_view(cub, cub->map.str[l][c]);
			}
			c++;
		}
		g++;
		l++;
	}
	printf("Player : pos_y = %f, pos_x = %f\n", cub->player.pos_y, cub->player.pos_x);
}

/*
void	define_angle(t_cub *cub)
{
	double	dim_wall;
	double	half_wall;

	dim_wall = 64.0;
	half_wall = 32.0;
	cub->rays.nb = 0;
	cub->player.angle = cub->player.view - half_wall;
	while (cub->rays.nb < SCREEN_W)
	{
		//init_ray(ray, cub);
		//dda(ray, cub);
		cub->player.angle += dim_wall / SCREEN_W;
		cub->rays.nb++;
	}
	printf("angle de vue joueur = %f\n", cub->player.angle);
}

void	player_dir(t_cub *cub, char	map)
{
	if (map == 'N')
	{
		cub->player.view = 90.0;
	}
	if (map == 'S')
	{
		cub->player.view = 270.0;
	}
	if (map == 'W')
	{
		cub->player.view = 180.0;
	}
	if (map == 'E')
	{
		cub->player.view = 360.0;
	}
	define_angle(cub);
}
*/
