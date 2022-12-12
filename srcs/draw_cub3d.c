/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 07:01:02 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/12 14:51:32 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	draw_color_backgound(t_cub *cub)
{
	int	middle_screen;
	int	x;

	middle_screen = SCREEN_W * SCREEN_H / 2 - 1;
	x = SCREEN_W * SCREEN_H - 1;
	while (x >= middle_screen)
	{
		cub->img.addr[x] = cub->map.color_floor;
		x--;
	}
	while (x >= 0)
	{
		cub->img.addr[x] = cub->map.color_sky;
		x--;
	}
}
