/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:04:03 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/05 18:13:31 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_up(t_cub *cub)
{
	cub->player.speed = 0.08;
	cub->player.rotspeed = 0.06;
	if (cub->map.rmap[(int)(cub->player.pos_y + cub->player.dir_y * cub->player.speed)][(int)cub->player.pos_x] != '1')
		cub->player.pos_y += cub->player.dir_y * cub->player.speed;
	if (cub->map.rmap[(int)(cub->player.pos_y)][(int)(cub->player.pos_x + cub->player.dir_x * cub->player.speed)] != '1')
		cub->player.pos_x += cub->player.dir_x * cub->player.speed;
}
