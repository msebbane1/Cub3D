/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:32:20 by lbally            #+#    #+#             */
/*   Updated: 2022/12/07 17:35:31 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculate_texture(t_cub	*cub)
{
	double	wall_x;

	if (cub->rays.side <= 1)
		wall_x = cub->player.pos_y + cub->rays.dist * cub->rays.dir_y;
	else
		wall_x = cub->player.pos_x + cub->rays.dist * cub->rays.dir_x;
	wall_x -= floor((wall_x));
	cub->rays.texture_x = (int)(wall_x
			*(double)(cub->map.texture[cub->rays.side].width));
	if (cub->rays.side <= 1 && cub->rays.dir_x > 0)
		cub->rays.texture_x = cub->map.texture[cub->rays.side].width
			- cub->rays.texture_x - 1;
	if (cub->rays.side > 1 && cub->rays.dir_y < 0)
		cub->rays.texture_x = cub->map.texture[cub->rays.side].width
			- cub->rays.texture_x - 1;
}

void	draw_walls(t_cub *cub, int start_draw, int end_draw)
{
	double	step;
	double	texture_pos;
	int		t_h;
	int		t_w;
	int		set_img;

	t_h = cub->map.texture[cub->rays.side].height;
	t_w = cub->map.texture[cub->rays.side].width;
	step = 1.0 * t_h / cub->rays.line_h;
	texture_pos = (start_draw - SCREEN_H / 2 + cub->rays.line_h / 2) * step;
	while (start_draw < end_draw)
	{	
		cub->rays.texture_y = (int)texture_pos & (t_h - 1);
		texture_pos += step;
		set_img = cub->map.texture[cub->rays.side].addr[cub->rays.texture_y
			* t_w + cub->rays.texture_x];
		cub->img.addr[start_draw * SCREEN_W + cub->rays.nb] = set_img;
		start_draw++;
	}
}

double	calculate_camera(t_cub *cub)
{
	return (2 * cub->rays.nb / D_W - 1);
}

void	ft_raycasting(t_cub *cub)
{
	int		start_draw;
	int		end_draw;

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
		cub->rays.line_h = (int)((D_H * cub->rays.ratio) / cub->rays.dist);
		start_draw = (-cub->rays.line_h / 2 + SCREEN_H / 2);
		if (start_draw < 0)
			start_draw = 0;
		end_draw = (cub->rays.line_h / 2 + SCREEN_H / 2);
		if (end_draw >= SCREEN_H)
			end_draw = SCREEN_H - 1;
		calculate_texture(cub);
		draw_walls(cub, start_draw, end_draw);
		cub->rays.nb++;
	}
}
