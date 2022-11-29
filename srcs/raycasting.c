/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:32:20 by lbally            #+#    #+#             */
/*   Updated: 2022/11/29 14:45:51 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


void	init_ray(t_ray *ray, t_cub *cub)
{
	double val;

	val = 2 * ray->nb / (double) WIDTH - 1;
	ray->x = (int) cub->player.pos_x;
	ray->y = (int) cub->player.pos_y;
	ray->dir_x = cub->player.dir_x + cub->player.plane_x * val;
	ray->dir_y = cub->player.dir_y + cub->player.plane_y * val;
	if (ray->dir_y == 0)
		ray->delta_x = 0;
	else if (ray->dir_x == 0)
		ray->delta_x = 1;
	else
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_x == 0)
		ray->delta_y = 0;
	else if (ray->dir_y == 0)
		ray->delta_y = 1;
	else
		ray->delta_y = fabs(1 / ray->dir_y);
	get_step(ray, cub);
	ray->hit = 0;
	ray->side = 0;
	ray->dist = 0;
}

void	dda(t_ray *ray, t_cub *cub)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->x += ray->step_x;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->y += ray->step_y;
			if (ray->step_y == -1)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (cub->map.rmap[ray->y][ray->x] == '1')
		{
			
			printf("hello\n");
			ray->hit = 1;
		}
	}
}

void	get_step(t_ray *ray, t_cub *cub)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (cub->player.pos_x - ray->x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->x - cub->player.pos_x + 1.0) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (cub->player.pos_y - ray->y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->y - cub->player.pos_y + 1.0) * ray->delta_y;
	}
}

void	raycasting(t_ray *ray, t_cub *cub)
{
	double	ratio;

	ratio = ((double) SCREEN_W / (double) SCREEN_H) / (4.0 / 3.0);
	ray->nb = 0;
	while (ray->nb < SCREEN_W)
	{
		init_ray(ray, cub);
		//dda(ray, cub);
		ray->dist = (ray->x - cub->player.pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
		if (ray->side == 0 || ray->side == 1)
			ray->dist = (ray->x - cub->player.pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
		else
			ray->dist = (ray->y - cub->player.pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
		ray->h = (int)(((double)SCREEN_H * ratio) / ray->dist);
		ray->nb++;
	}
}