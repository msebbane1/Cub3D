/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:06 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/12 17:04:02 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_spaces(t_cub *cub)
{
	int	l;
	int	t;
	int	g;
	int	u;

	l = cub->map.index_spaces;
	t = 0;
	u = 0;
	g = 0;
	while (cub->map.str[l] != NULL)
	{
		g = 0;
		u = 0;
		if (cub->map.str[l][0] == '\n' || cub->map.str[l][0] == '\0')
			t++;
		while (cub->map.str[l][u])
		{
			if (t != 0 && u == 0 && (cub->map.str[l][u] != '\n' || cub->map.str[l][u] != '\0'))
				return (1);
			if (cub->map.str[l][u] != '0' && cub->map.str[l][u] != '1')
				g++;
			u++;
		}
		printf("UUUU ===== %d\n", u);
		printf("GGGG ===== %d\n", g);
		if (u == g && u != 0 && t != 0)
			return (1);
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
	while (cub->map.str[l][c] != '\n' && cub->map.str[l][c] != '\0')
	{
		if (cub->map.str[l][c] != '1')
			return (1);
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

int	line_size_max(t_cub *cub)
{
	int		l;
	int		size_max;

	l = cub->map.index_map;
	size_max = 0;
	while (cub->map.str[l])
	{
		if (size_max < ft_strlen(cub->map.str[l]))
			size_max = ft_strlen(cub->map.str[l]);
		l++;
	}
	return (size_max);
}
