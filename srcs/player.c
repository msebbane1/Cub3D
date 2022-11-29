/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:53 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/29 14:40:10 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	player(t_cub *cub)
{
	int		c;
	int		g;
	int		l;

	l = 0;
	g = 0;
	while (cub->map.rmap[l] != NULL)
	{
		c = 0;
		while (cub->map.rmap[l][c])
		{
			if (cub->map.rmap[l][c] == 'N' || cub->map.rmap[l][c] == 'S'
				|| cub->map.rmap[l][c] == 'W' ||cub->map.rmap[l][c] == 'E')
			{
				cub->player.pos_x = c;
				cub->player.pos_y = g;
				cub->player.plane_x =0.0;
				cub->player.plane_y =0.66;
				if (cub->map.rmap[l][c] == 'N')
				{
					cub->player.dir_x = 1;
					cub->player.dir_y = 0;
				}
				if (cub->map.rmap[l][c] == 'S')
				{
					cub->player.dir_x = -1;
					cub->player.dir_y = 0;
				}
				if (cub->map.rmap[l][c] == 'W')
				{
					cub->player.dir_x = 0;
					cub->player.dir_y = -1;
				}
				if (cub->map.rmap[l][c] == 'E')
				{
					cub->player.dir_x = 0;
					cub->player.dir_y = 1;
				}
			}
			c++;
		}
		g++;
		l++;
	}
}
