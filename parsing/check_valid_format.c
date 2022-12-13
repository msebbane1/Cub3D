/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:54 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/13 16:56:25 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_texture(t_cub *cub, char **map_split)
{
	if (!ft_strcmp(map_split[0], "NO"))
	{
		cub->map.path_no = map_split[1];
		cub->map.no++;
	}
	if (!ft_strcmp(map_split[0], "SO"))
	{
		cub->map.path_so = map_split[1];
		cub->map.so++;
	}
	if (!ft_strcmp(map_split[0], "WE"))
	{
		cub->map.path_we = map_split[1];
		cub->map.we++;
	}
	if (!ft_strcmp(map_split[0], "EA"))
	{
		cub->map.path_ea = map_split[1];
		cub->map.ea++;
	}
}

int	parse_color(t_cub *cub, char **map_split, int *nb)
{
	if (!ft_strcmp(map_split[0], "F") || !ft_strcmp(map_split[0], "C"))
	{
		ft_trim_colors(map_split);
		if (!ft_strcmp(map_split[0], "C"))
		{
			cub->map.c++;
			check_colors(cub, map_split[1], 'C');
			*nb = 1;
		}
		else if (!ft_strcmp(map_split[0], "F"))
		{
			cub->map.f++;
			check_colors(cub, map_split[1], 'F');
			*nb = 1;
		}
	}
	else
		return (0);
	return (1);
}

int	parse_texture(t_cub *cub, char **map_split, int *nb_texture)
{
	int		error;

	if (!ft_strcmp(map_split[0], "SO") || !ft_strcmp(map_split[0], "NO")
		|| !ft_strcmp(map_split[0], "EA") || !ft_strcmp(map_split[0], "WE"))
	{
		check_texture_path(map_split[1], &error);
		ft_trim_texture(cub, map_split);
		if (error == 0)
			init_texture(cub, map_split);
		*nb_texture = 1;
	}
	else
		return (0);
	return (1);
}

int	check_parse_format(t_cub *cub, char **map_split, int *nb)
{
	char	*temp;

	ft_trim_format(cub, map_split);
	if (parse_color(cub, map_split, nb))
	{
		free_tab(map_split);
		return (1);
	}
	if (parse_texture(cub, map_split, nb))
	{
		temp = map_split[0];
		free(map_split);
		free(temp);
		return (1);
	}
	else
	{
		free_tab(map_split);
		return (0);
	}
	free_tab(map_split);
	return (1);
}

void	check_valid_format(t_cub *cub)
{
	int		i;
	int		nb_texture;
	char	**map_split;

	i = 0;
	nb_texture = 0;
	while (cub->map.str[i])
	{
		map_split = split_map(cub, i, map_split);
		if (check_parse_format(cub, map_split, &nb_texture))
			cub->map.index++;
		i++;
	}
	cub->map.index_map = check_new_index(cub);
	if (cub->map.index == 0)
		error_msg("Error\nMissing format");
	if ((cub->map.index != 6) && !check_walls_first_line(cub))
		error_msg("Error\nInvalid format :Missing textures or colors");
	if ((cub->map.no != 1 || cub->map.so != 1 || cub->map.we != 1
			|| cub->map.ea != 1 || cub->map.c != 1 || cub->map.no != 1))
		error_msg("Error\nInvalid format :Double textures or colors");
	if (cub->map.str[cub->map.index_map] == NULL)
		error_msg("Error\nMissing map");
}
