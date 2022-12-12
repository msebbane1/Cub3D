/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:59:32 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/12 14:17:24 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_convert_rgb_floor(t_cub *cub, char **map_split)
{
	cub->map.floor[0] = ft_atoi(map_split[0]);
	cub->map.floor[1] = ft_atoi(map_split[1]);
	cub->map.floor[2] = ft_atoi(map_split[2]);
}

void	ft_convert_rgb_sky(t_cub *cub, char **map_split)
{
	cub->map.sky[0] = ft_atoi(map_split[0]);
	cub->map.sky[1] = ft_atoi(map_split[1]);
	cub->map.sky[2] = ft_atoi(map_split[2]);
}

void	ft_convert_rgb(char c, t_cub *cub, char **map_split)
{
	if (c == 'F')
	{
		ft_convert_rgb_floor(cub, map_split);
		cub->map.color_floor = create_trgb(0, cub->map.floor[0],
				cub->map.floor[1], cub->map.floor[2]);
	}
	if (c == 'C')
	{
		ft_convert_rgb_sky(cub, map_split);
		cub->map.color_sky = create_trgb(0, cub->map.sky[0],
				cub->map.sky[1], cub->map.sky[2]);
	}
}

void	check_colors(t_cub *cub, char *str, char c)
{
	char	**map_split;
	int		i;
	int		rgb;

	i = 0;
	if (!str)
		error_msg("Error\nInvalid RGB");
	if (check_virgule(str))
		error_msg("Error\nInvalid RGB: must be separate by 2 virgule");
	if (ft_check_letters(str))
		error_msg("Error\ninvalid RGB: Write numbers for colors");
	map_split = ft_split(str, ',');
	while (map_split[i])
	{
		rgb = ft_atoi(map_split[i]);
		if ((rgb < 0 || rgb > 255) || !ft_strcmp(str, "-"))
			error_msg("Error\ninvalid RGB: colors between 0 and 255");
		i++;
	}
	if (i != 3)
		error_msg("Error\ninvalid RBG: You must have 3 colors");
	ft_convert_rgb(c, cub, map_split);
	free_tab(map_split);
}
