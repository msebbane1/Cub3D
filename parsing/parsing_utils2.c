/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:02:47 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/13 16:38:08 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_check_letters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 58 && line[i] <= 127)
			|| (line[i] >= 33 && line[i] <= 43)
			|| (line[i] >= 46 && line[i] <= 47))
			return (1);
		i++;
	}
	return (0);
}

int	check_virgule(char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == ',')
			y++;
		i++;
	}
	if (y != 2)
		return (1);
	return (0);
}

int	check_new_index(t_cub *cub)
{
	int		i;
	int		index;

	i = 0;
	index = cub->map.index_map;
	while (cub->map.str[i])
	{
		if (ft_skip_format(cub->map.str[i]))
			index++;
		else
			break ;
		i++;
	}
	return (index);
}

int	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E'
		&& c != ' ' && c != '\t'
		&& c != '\r' && c != '\f'
		&& c != '\v')
		return (1);
	return (0);
}

int	check_walls_first_line(t_cub *cub)
{
	int	l;

	l = cub->map.index_map;
	while (cub->map.str[l])
	{
		if (cub->map.str[l][0] == '0' || cub->map.str[l][0] == 'N'
			|| cub->map.str[l][0] == 'W' || cub->map.str[l][0] == 'E'
			|| cub->map.str[l][0] == 'S')
			return (1);
		l++;
	}
	return (0);
}
