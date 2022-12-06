/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:04:03 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/06 17:23:08 by msebbane         ###   ########.fr       */
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
	int	pos_x;
	int	pos_y;
	int	dir_x;
	int	dir_y;
	int	speed;

	pos_x = (int)cub->player.pos_x;
	pos_y = (int)cub->player.pos_y;
	dir_y = (int)cub->player.dir_y;
	dir_x = (int)cub->player.dir_x;
	speed = (int)SPEED;
	if (cub->map.rmap[pos_y - dir_y * speed][pos_x] != '1')
		cub->player.pos_y -= cub->player.dir_y * SPEED;
	if (cub->map.rmap[pos_y][pos_x - dir_x * speed] != '1')
		cub->player.pos_x -= cub->player.dir_x * SPEED;
}

void	move_forward(t_cub *cub)
{
	int	pos_x;
	int	pos_y;
	int	dir_x;
	int	dir_y;
	int	speed;

	pos_x = (int)cub->player.pos_x;
	pos_y = (int)cub->player.pos_y;
	dir_y = (int)cub->player.dir_y;
	dir_x = (int)cub->player.dir_x;
	speed = (int)SPEED;
	printf("map = %c\n", cub->map.rmap[pos_y + dir_y * speed][pos_x]);
	printf("pos_x = %d\n", pos_x);
	if (cub->map.rmap[pos_y + dir_y * speed][pos_x] != '1')
	{
		printf("ff2\n");
		//printf("dirx %f, diry %f\n", cub->)
		cub->player.pos_y += cub->player.dir_y * SPEED;
	}
	if (cub->map.rmap[pos_y][pos_x + dir_x * speed] != '1')
	{
		printf("ff\n");
		cub->player.pos_x += cub->player.dir_x * SPEED;
	}
	/*else if (cub->map.rmap[pos_y][pos_x + dir_x * speed] == '1')
	{
		cub->player.pos_x += cub->player.dir_x * SPEED;
		return ;
	}
	else if (cub->map.rmap[pos_y + dir_y * speed][pos_x] == '1')
	{
		cub->player.pos_y += cub->player.dir_y * SPEED;
		return ;
	}*/
	
}
