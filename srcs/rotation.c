/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:42:07 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/12 14:43:11 by msebbane         ###   ########.fr       */
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

void	mouse_left(t_cub *cub)
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

void	mouse_right(t_cub *cub)
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
