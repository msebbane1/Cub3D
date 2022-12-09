/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:00:06 by lbally            #+#    #+#             */
/*   Updated: 2022/12/09 18:10:54 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	remplace(t_cub *cub)
{
	int		i;
	int		w;
	int		t;
	int		y;

	i = 0;
	w = 0;
	t = 0;
	y = cub->map.index_spaces;
	while (cub->map.str[y])
	{
		w = 0;
		while (cub->map.str[y][w])
			w++;
		if (i < w)
			i = w;
		y++;
		t++;
	}
	w = 0;
	cub->map.size.y = t + 1;
	cub->map.size.x = i + 1;
	cub->map.rmap = malloc(sizeof(char *) * (cub->map.size.y) + 1);
	t = 0;
	y = cub->map.index_spaces;
	while (cub->map.str[y])
	{
		w = 0;
		while (cub->map.str[y][w])
			w++;
		cub->map.rmap[t] = malloc(sizeof(char) * w + 1);
		w = 0;	
		while (cub->map.str[y][w])
		{
			cub->map.rmap[t][w] = cub->map.str[y][w];
			w++;
		}
		cub->map.rmap[t][w] = '\0';
		y++;
		t++;
	}
	cub->map.rmap[t] = NULL;
}
