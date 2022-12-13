/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:43:05 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/13 16:56:14 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	**newmap(char **map_split, int t, int i, char **new_map)
{
	int	j;
	int	g;

	j = 0;
	g = 0;
	while (map_split[i][j])
	{
		new_map[t][g] = map_split[i][j];
		g++;
		j++;
	}
	new_map[t][g] = '\0';
	return (new_map);
}

int	index_tab(char **map_split, int g, int l, int c)
{
	if (map_split[l][c] == '\t' || map_split[l][c] == ' ')
		g++;
	return (g);
}

char	**parse_space(char **map_split, int l, int c, char **new_map)
{
	int		g;
	int		t;

	t = 0;
	while (map_split[l])
	{
		c = 0;
		g = 0;
		while (map_split[l][c])
		{
			g = index_tab(map_split, g, l, c);
			c++;
		}
		if (c == g)
			l++;
		else
		{
			new_map[t] = malloc(sizeof(char) * c + 1);
			new_map = newmap(map_split, t, l, new_map);
			t++;
			l++;
		}
	}
	new_map[t] = NULL;
	return (new_map);
}

char	**malloc_map_space(char **map_split)
{
	int		l;
	int		t;
	int		c;
	int		g;
	char	**new_map;

	l = 0;
	t = 0;
	while (map_split[l])
	{
		g = 0;
		c = 0;
		while (map_split[l][c])
		{
			if (map_split[l][c] == '\t')
				g++;
			c++;
		}
		if (c == g)
			t++;
		l++;
	}
	new_map = malloc(sizeof(char *) * (l - t + 1));
	return (new_map);
}


char	**split_map(t_cub *cub, int i, char **map_split)
{
	char	**tmp;
//	char	*temp;
	char	**new_map;
	int		l;
	int		c;

	l = 0;
	c = 0;
//	while (cub->map.str[i][c])
//		c++;
//	temp = malloc(sizeof(char) * c + 1);
	c = 0;
	while (cub->map.str[i][c])
	{
		if (cub->map.str[i][c] == '\t')
			cub->map.str[i][c] = ' ';
		else
			cub->map.str[i][c] = cub->map.str[i][c];
		c++;
	}
//	temp[c] = '\0';
	map_split = ft_split(cub->map.str[i], ' ');
	tmp = map_split;
	new_map = malloc_map_space(tmp);
	map_split = parse_space(tmp, l, c, new_map);
	free_tab(tmp);
//	free(temp);
	return (map_split);
}
