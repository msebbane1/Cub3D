/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:32:20 by lbally            #+#    #+#             */
/*   Updated: 2022/12/06 17:21:24 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_walls(t_cub *cub, int start, int end)
{
	while (start < end)
	{
		cub->img.addr[start * SCREEN_W + cub->rays.nb]
			= create_trgb(0, 255, 255, 255);
		start++;
	}
}

double	calculate_camera(t_cub *cub)
{
	return (2 * cub->rays.nb / D_W - 1);
}

void	ft_raycasting(t_cub *cub)
{
	int		start;
	int		end;

	cub->rays.nb = 0;
	while (cub->rays.nb < SCREEN_W)
	{
		cub->rays.camera = calculate_camera(cub);
		cub->rays.map_x = (int)cub->player.pos_x;
		cub->rays.map_y = (int)cub->player.pos_y;
		init_ray(cub);
		while (cub->rays.hit == 0)
		{
			init_hit(cub);
			if (cub->map.rmap[cub->rays.map_y][cub->rays.map_x] == '1')
				cub->rays.hit = 1;
		}
		init_ray_dist(cub);
		cub->rays.h = (int)((D_H * cub->rays.ratio) / cub->rays.dist);
		start = (-cub->rays.h / 2 + SCREEN_H / 2);
		end = (cub->rays.h / 2 + SCREEN_H / 2);
		if (start < 0)
			start = 0;
		if (end > SCREEN_H)
			end = SCREEN_H - 1;
		draw_walls(cub, start, end);
		cub->rays.nb++;
	}
}
