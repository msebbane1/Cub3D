/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:53 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/24 06:44:18 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

double	set_fov_dir(char c, int mod)
{
	if (mod)
	{
		if (c == 'N' || c == 'E')
			return (0.66);
		return (-0.66);
	}
	if (c == 'W' || c == 'N')
		return (-1.);
	return (1.);
}

void	init_pos_player(t_cub *cub, char c)
{
	if (c == 'N' || c == 'S')
	{
		cub->player.dir_x = 0.0;
		cub->player.dir_y = set_fov_dir(c, 0);
		cub->player.plane_x = set_fov_dir(c, 1);
		cub->player.plane_y = 0.0;
	}
	else if (c == 'E' || c == 'W')
	{
		cub->player.dir_x = set_fov_dir(c, 0);
		cub->player.dir_y = 0.;
		cub->player.plane_x = 0.;
		cub->player.plane_y = set_fov_dir(c, 1);
	}
}
void	player(t_cub *cub)
{
	int		c;
	int		l;

	l = cub->map.index_spaces;
	c = 0;
	while (cub->map.str[l] != NULL)
	{
		c = 0;
		while (cub->map.str[l][c])
		{
			if (cub->map.str[l][c] == 'N' || cub->map.str[l][c] == 'S'
				|| cub->map.str[l][c] == 'W' || cub->map.str[l][c] == 'E')
			{
				cub->player.pos_x = c; // + 0,5 ?
				cub->player.pos_y = l;
				init_pos_player(cub, cub->map.str[l][c]);
			}
			c++;
		}
		l++;
	}
	return (0);
}
