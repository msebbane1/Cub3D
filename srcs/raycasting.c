/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:32:20 by lbally            #+#    #+#             */
/*   Updated: 2022/11/28 17:42:50 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycasting(t_ray *ray, t_cub *cub)
{
	ray->nb = 0;
	while(ray->nb < WIDTH)
	{
		init_ray(ray, cub);
		dda(ray);
	}
}

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

void	dda(t_ray *ray)
{
	while(ray->hit == 0)
	{
		if(ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->x += ray->step_x;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->y += ray->step_y;
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