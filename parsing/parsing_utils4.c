/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:41:59 by lbally            #+#    #+#             */
/*   Updated: 2022/12/12 18:42:23 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	veref(t_cub *cub, int i)
{
	int	j;
	int	g;

	j = 0;
	g = 0;
	while (cub->map.str[i][j])
	{
		if (cub->map.str[i][j] != '0' && cub->map.str[i][j] != '1')
			g++;
		j++;
	}
	printf("JJJJ ===== %d\n", j);
	printf("GGGG ===== %d\n", g);
	return (j - g);
}
