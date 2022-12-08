/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:39 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/08 15:59:22 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_new_index(t_cub *cub)
{
	int		i;
	int		index;

	i = 0;
	index = cub->map.index_spaces;
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

int	parse_color(t_cub *cub, char **map_split)
{
	int	t;

	t = 2;
	if (!ft_strcmp(map_split[0], "F") || !ft_strcmp(map_split[0], "C"))
	{
		while (map_split[t])
		{
			map_split[1] = ft_strjoin_2(map_split[1], map_split[t]);
			t++;
		}
	}
	if (!ft_strcmp(map_split[0], "C"))
	{
		check_colors(cub, map_split[1], 'C');
		cub->map.c++;
	}
	else if (!ft_strcmp(map_split[0], "F"))
	{
		check_colors(cub, map_split[1], 'F');
		cub->map.f++;
	}
	else
		return (0);
	return (1);
}

int	parse_texture(t_cub *cub, char **map_split)
{
	int	y;
	int	error;

	y = 0;
	//printf("spli2 = %s\n", map_split[2]);
	if (!ft_strcmp(map_split[0], "SO"))
	{
		while (map_split[y])
		{
			map_split[y] = ft_strtrim(map_split[y], "\t");
			y++;
		}
	}
	/*printf("i = %d\n", cub->map.index);
	if (map_split[2] != NULL  && cub->map.index <= 6)
	{
		printf("dddd\n");
		if (ft_check_letters(map_split[2]))
			error_msg("fd");
	}*/
	if (!ft_strcmp(map_split[0], "NO"))
	{
		check_texture_path(map_split[1], &error);
		cub->map.path_no = map_split[1];
		cub->map.no++;
	}
	else if (!ft_strcmp(map_split[0], "SO"))
	{
		check_texture_path(map_split[1], &error);
		cub->map.path_so = map_split[1];
		cub->map.so++;
	}
	else if (!ft_strcmp(map_split[0], "WE"))
	{
		check_texture_path(map_split[1], &error);
		cub->map.path_we = map_split[1];
		cub->map.we++;
	}
	else if (!ft_strcmp(map_split[0], "EA"))
	{
		check_texture_path(map_split[1], &error);
		cub->map.path_ea = map_split[1];
		cub->map.ea++;
	}
	else
		return (0);
	return (1);
}

int	check_parse_format(t_cub *cub, char **map_split)
{
	int	y;

	y = 0;
	while (map_split[y] && cub->map.index < 6)
	{
		map_split[y] = ft_strtrim(map_split[y], "\t");
		y++;
	}
	if (parse_texture(cub, map_split))
		return (1);
	else if (parse_color(cub, map_split))
		return (1);
	else
	{
		//free map_split
		return (0);
	}
	return (1);
}

void	check_valid_format(t_cub *cub)
{
	int		i;
	char	**map_split;

	i = 0;
	while (cub->map.str[i])
	{
		map_split = ft_split(cub->map.str[i], ' ');
		if (check_parse_format(cub, map_split))
			cub->map.index++;
		i++;
	}
	cub->map.index_spaces = check_new_index(cub);
	printf("index = %d\n", cub->map.index);
	if (cub->map.index == 0)
		error_msg("Error\nMissing format");
	if ((cub->map.index != 6 && !check_walls_first_line_char(cub)))
		error_msg("Error\nInvalid format :Missing textures or colors");
	if ((cub->map.no != 1 || cub->map.so != 1 || cub->map.we != 1
			|| cub->map.ea != 1 || cub->map.c != 1 || cub->map.no != 1))
		error_msg("Error\nInvalid format :Double textures or colors");
}
/*
*Creer une erreur si il y a que la map [missing map] check espace ou 1 apres index + 1
*Mauvaise gestion des tab et espaces + color apres un espace split
*C 148,216----,252 gerer apres les nombre
*quand tu fais entrer et rajoute des 1 probleme
*mix space et tab
*/