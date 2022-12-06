/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:04:03 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/06 17:56:02 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rotate_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_x;
	old_plane_x = cub->player.plane_x;
	cub->player.dir_x = cub->player.dir_x * cos(R_SPEED)
		- cub->player.dir_y * sin(R_SPEED);
	cub->player.dir_y = old_dir_x * sin(R_SPEED)
		+ cub->player.dir_y * cos(R_SPEED);
	cub->player.plane_x = cub->player.plane_x * cos(R_SPEED)
		- cub->player.plane_y * sin(R_SPEED);
	cub->player.plane_y = old_plane_x * sin(R_SPEED)
		+ cub->player.plane_y * cos(R_SPEED);
}

void	rotate_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_x;
	old_plane_x = cub->player.plane_x;
	cub->player.dir_x = cub->player.dir_x * cos(-R_SPEED)
		- cub->player.dir_y * sin(-R_SPEED);
	cub->player.dir_y = old_dir_x * sin(-R_SPEED)
		+ cub->player.dir_y * cos(-R_SPEED);
	cub->player.plane_x = cub->player.plane_x * cos(-R_SPEED)
		- cub->player.plane_y * sin(-R_SPEED);
	cub->player.plane_y = old_plane_x * sin(-R_SPEED)
		+ cub->player.plane_y * cos(-R_SPEED);
}

void	move_backwards(t_cub *cub)
{
	if (cub->map.rmap[(int)(cub->player.pos_y - cub->player.dir_y * SPEED)]
		[(int)cub->player.pos_x] != '1')
		cub->player.pos_y -= cub->player.dir_y * SPEED;
	if (cub->map.rmap[(int)cub->player.pos_y]
		[(int)(cub->player.pos_x - cub->player.dir_x * SPEED)] != '1')
		cub->player.pos_x -= cub->player.dir_x * SPEED;
}

void	move_forward(t_cub *cub)
{
	if (cub->map.rmap[(int)(cub->player.pos_y + cub->player.dir_y * SPEED)]
		[(int)cub->player.pos_x] != '1')
		cub->player.pos_y += cub->player.dir_y * SPEED;
	if (cub->map.rmap[(int)cub->player.pos_y]
		[(int)(cub->player.pos_x + cub->player.dir_x * SPEED)] != '1')
		cub->player.pos_x += cub->player.dir_x * SPEED;
}
