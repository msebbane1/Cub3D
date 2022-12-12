/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:00:06 by lbally            #+#    #+#             */
/*   Updated: 2022/12/12 14:34:37 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	malloc_new_map(t_cub *cub)
{
	int	l;
	int	c;
	int	t;
	int	i;

	l = cub->map.index_map;
	t = 0;
	while (cub->map.str[l])
	{
		c = 0;
		while (cub->map.str[l][c])
			c++;
		if (i < c)
			i = c;
		l++;
		t++;
	}
	cub->map.size.y = t + 1;
	cub->map.size.x = i + 1;
	cub->map.rmap = malloc(sizeof(char *) * (cub->map.size.y) + 1);
}

void	remplace_map(t_cub *cub)
{
	int		c;
	int		t;
	int		l;

	l = cub->map.index_map;
	t = 0;
	malloc_new_map(cub);
	while (cub->map.str[l])
	{
		c = 0;
		while (cub->map.str[l][c])
			c++;
		cub->map.rmap[t] = malloc(sizeof(char) * c + 1);
		c = 0;
		while (cub->map.str[l][c])
		{
			cub->map.rmap[t][c] = cub->map.str[l][c];
			c++;
		}
		cub->map.rmap[t][c] = '\0';
		l++;
		t++;
	}
	cub->map.rmap[t] = NULL;
}
