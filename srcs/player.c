/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:53 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/23 17:02:08 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


void	init_pos_player(t_cub *cub, int y, int x)
{
	cub->player.pos_x = x;
	cub->player.pos_y = y;
	
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
				init_pos_player(cub, l, c, cub->map.str[l][c]);
			c++;
		}
		l++;
	}
	return (0);
}
