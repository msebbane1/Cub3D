/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:59:32 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/22 16:39:49 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_check_letters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 'A' && line[i] <= 'Z')
			|| (line[i] >= 'a' && line[i] <= 'z'))
			return (1);
		i++;
	}
	return (0);
}

void	ft_convert_rgb_floor(t_cub *cub, char **map_split)
{
	cub->map.floor[0] = ft_atoi(map_split[0]) << 16;
	cub->map.floor[1] = ft_atoi(map_split[1]) << 8;
	cub->map.floor[2] = ft_atoi(map_split[2]);
	printf("floor = %d\n", cub->map.floor[0]);
}

void	ft_convert_rgb_sky(t_cub *cub, char **map_split)
{
	cub->map.sky[0] = ft_atoi(map_split[0]) << 16;
	cub->map.sky[1] = ft_atoi(map_split[1]) << 8;
	cub->map.sky[2] = ft_atoi(map_split[2]);
}

void	check_colors(t_cub *cub, char *str, char c)
{
	char	**map_split;
	int		i;
	int		rgb;

	i = 0;
	rgb = 0;
	printf("str = %s\n", str);
	if (ft_check_letters(str))
		error_msg("Error\ninvalid RGB: Write numbers for colors");
	map_split = ft_split(str, ',');
	while (map_split[i])
	{
		rgb = ft_atoi(map_split[i]);
		printf("rgb = %d\n", rgb);
		if ((rgb < 0 || rgb > 255) || !ft_strcmp(str, "-"))
			error_msg("Error\ninvalid RGB: colors between 0 and 255");
		i++;
	}
	if (i != 3)
		error_msg("Error\ninvalid RBG: You must have 3 colors");
	if (i == 3 && c == 'F')
		ft_convert_rgb_floor(cub, map_split);
	if (i == 3 && c == 'C')
		ft_convert_rgb_sky(cub, map_split);
	printf(" i = %d\n", i);
}
