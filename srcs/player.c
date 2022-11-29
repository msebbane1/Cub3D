/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:53 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/29 14:47:56 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	player_dir(t_cub *cub, int l, int c)
{
	if (cub->map.str[l][c] == 'N')
	{
		cub->player.dir_x = 1;
		cub->player.dir_y = 0;
	}
	if (cub->map.str[l][c] == 'S')
	{
		cub->player.dir_x = -1;
		cub->player.dir_y = 0;
	}
	if (cub->map.str[l][c] == 'W')
	{
		cub->player.dir_x = 0;
		cub->player.dir_y = -1;
	}
	if (cub->map.str[l][c] == 'E')
	{
		cub->player.dir_x = 0;
		cub->player.dir_y = 1;
	}
}

void	position_player(t_cub *cub)
{
	int		c;
	int		l;
	int		g;

	l = cub->map.index_spaces;
	g = 0;
	cub->player.plane_x = 0.0;
	cub->player.plane_y = 0.66;
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c])
		{
			if (cub->map.str[l][c] == 'N' || cub->map.str[l][c] == 'S'
				|| cub->map.str[l][c] == 'W' || cub->map.str[l][c] == 'E')
			{
				cub->player.pos_x = c;
				cub->player.pos_y = g;
				player_dir(cub, l, c);
			}
			c++;
		}
		g++;
		l++;
	}
	printf("Player : pos_y = %f, pos_x = %f\n", cub->player.pos_y, cub->player.pos_x);
}
