/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:53 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/12 14:35:05 by msebbane         ###   ########.fr       */
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

	l = 0;
	g = 0;
	while (cub->map.rmap[l] != NULL)
	{
		c = 0;
		while (cub->map.rmap[l][c])
		{
			if (cub->map.rmap[l][c] == 'N' || cub->map.rmap[l][c] == 'S'
				|| cub->map.rmap[l][c] == 'W' || cub->map.rmap[l][c] == 'E')
			{
				cub->player.pos_x += c;
				cub->player.pos_y += g;
				init_angle_view(cub, cub->map.rmap[l][c]);
			}
			c++;
		}
		g++;
		l++;
	}
}
