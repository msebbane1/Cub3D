/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:06 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/13 14:11:03 by lbally           ###   ########.fr       */
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
	return (j - g);
}

int	ristourne(t_cub *cub, int l)
{
	if (veref(cub, l))
		return (1);
	if (cub->map.str[l][0] != '\n' && cub->map.str[l][0] != '\0'
		&& cub->map.str[l][0] != '\t' && cub->map.str[l][0] != ' ')
		return (1);
	return (0);
}

int	check_spaces(t_cub *cub, int l, int t)
{
	int	d;

	d = 0;
	while (cub->map.str[l] != NULL)
	{
		if (t != 0)
		{
			if (ristourne(cub, l))
				return (1);
		}
		else
		{
			if (cub->map.str[l][0] == '\n' || cub->map.str[l][0] == '\0')
				t++;
			else
			{
				if (veref(cub, l) && d != 0)
					return (1);
				if (!veref(cub, l))
					d++;
			}
		}
		l++;
	}
	return (0);
}

int	check_start_line(t_cub *cub)
{
	int		c;
	int		l;

	l = cub->map.index_map;
	c = 0;
	while (cub->map.str[l][c])
	{
		if (cub->map.str[l][c] != '1'
			&& cub->map.str[l][c] != '\t' && cub->map.str[l][c] != ' ')
		{
			printf("LLALA === %s\n", cub->map.str[l]);
			return (1);
		}
		c++;
	}
	return (0);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
