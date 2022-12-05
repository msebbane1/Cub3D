/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:53:28 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/05 17:55:40 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_ray_dist(t_cub *cub)
{
	cub->rays.dist = (cub->rays.x - cub->player.pos_x
			+ (1 - cub->rays.step_x) / 2) / cub->rays.dir_x;
	if (cub->rays.side == 0 || cub->rays.side == 1)
		cub->rays.dist = (cub->rays.x - cub->player.pos_x
				+ (1 - cub->rays.step_x) / 2) / cub->rays.dir_x;
	else
		cub->rays.dist = (cub->rays.y - cub->player.pos_y
				+ (1 - cub->rays.step_y) / 2) / cub->rays.dir_y;
}

void	init_hit(t_cub *cub)
{
	if (cub->rays.side_x < cub->rays.side_y)
	{
		cub->rays.side_x += cub->rays.delta_x;
		cub->rays.x += cub->rays.step_x;
	}
	else
	{
		cub->rays.side_y += cub->rays.delta_y;
		cub->rays.y += cub->rays.step_y;
		if (cub->rays.step_y == -1)
			cub->rays.side = 2;
		else
			cub->rays.side = 3;
	}
}

void	init_step(t_cub *cub)
{
	if (cub->rays.dir_x < 0)
	{
		cub->rays.step_x = -1;
		cub->rays.side_x = (cub->player.pos_x - cub->rays.x)
			* cub->rays.delta_x;
	}
	else
	{
		cub->rays.step_x = 1;
		cub->rays.side_x = (cub->rays.x - cub->player.pos_x + 1.0)
			* cub->rays.delta_x;
	}
	if (cub->rays.dir_y < 0)
	{
		cub->rays.step_y = -1;
		cub->rays.side_y = (cub->player.pos_y - cub->rays.y)
			* cub->rays.delta_y;
	}
	else
	{
		cub->rays.step_y = 1;
		cub->rays.side_y = (cub->rays.y - cub->player.pos_y + 1.0)
			* cub->rays.delta_y;
	}
}

void	init_delta(t_cub *cub)
{
	if (cub->rays.dir_y == 0)
		cub->rays.delta_x = 0;
	else if (cub->rays.dir_x == 0)
		cub->rays.delta_x = 1;
	else
		cub->rays.delta_x = fabs(1 / cub->rays.dir_x);
	if (cub->rays.dir_x == 0)
		cub->rays.delta_y = 0;
	else if (cub->rays.dir_y == 0)
		cub->rays.delta_y = 1;
	else
		cub->rays.delta_y = fabs(1 / cub->rays.dir_y);
}

void	init_ray(t_cub *cub)
{
	cub->rays.dir_x = cub->player.dir_x + cub->player.plane_x * cub->rays.rayon;
	cub->rays.dir_y = cub->player.dir_y + cub->player.plane_y * cub->rays.rayon;
	cub->rays.hit = 0;
	cub->rays.side = 0;
	cub->rays.dist = 0;
	init_delta(cub);
	init_step(cub);
}
