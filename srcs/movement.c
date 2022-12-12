/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:43:21 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/12 14:43:31 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	move_right(t_cub *cub)
{
	if (cub->map.rmap[(int)(cub->player.pos_y + cub->player.plane_y * SPEED)]
		[(int)cub->player.pos_x] != '1')
		cub->player.pos_y += cub->player.plane_y * SPEED;
	if (cub->map.rmap[(int)cub->player.pos_y]
		[(int)(cub->player.pos_x + cub->player.plane_x * SPEED)] != '1')
		cub->player.pos_x += cub->player.plane_x * SPEED;
}

void	move_left(t_cub *cub)
{
	if (cub->map.rmap[(int)(cub->player.pos_y - cub->player.plane_y * SPEED)]
		[(int)cub->player.pos_x] != '1')
		cub->player.pos_y -= cub->player.plane_y * SPEED;
	if (cub->map.rmap[(int)cub->player.pos_y]
		[(int)(cub->player.pos_x - cub->player.plane_x * SPEED)] != '1')
		cub->player.pos_x -= cub->player.plane_x * SPEED;
}
