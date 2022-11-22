/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:39 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/22 18:08:17 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*int	check_path_texture(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->map.wall[i].img == NULL)
		{
			i++;
			return (1);
		}
	}
	return (0);
}*/

void	check_texture_path(char	*path)
{
	int	fd;
	int	fd2;

	fd = open(path, O_RDONLY);
	fd2 = open(path, O_DIRECTORY);
	if (fd < 0)
	{
		error_msg("Error\nInvalid texture : doesn't exist");
		close(fd);
	}
	if (fd2 != -1)
	{
		error_msg("Error\nTexture path invalid :Directory");
		close(fd2);
	}
	close(fd);
	close(fd2);
	//Fonction qui doit checker .xpm pour la texture
}

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

/*int	parse_color(t_cub *cub, char **map_split)
{
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
		return (1);
	return (0);
}*/

void	parse_texture(t_cub *cub, char **map_split)
{
	if (!ft_strcmp(map_split[0], "NO"))
	{
		cub->map.wall[0] = init_img(cub->mlx, map_split[1]);
		cub->map.no++;
		cub->map.index++;
		printf("no2 = %d\n", cub->map.no);
	}
	else if (!ft_strcmp(map_split[0], "SO"))
	{
		cub->map.wall[1] = init_img(cub->mlx, map_split[1]);
		cub->map.so++;
		cub->map.index++;
		printf("no = %d\n", cub->map.so);
	}
	else if (!ft_strcmp(map_split[0], "WE"))
	{
		cub->map.wall[2] = init_img(cub->mlx, map_split[1]);
		cub->map.we++;
		cub->map.index++;
	}
	else if (!ft_strcmp(map_split[0], "EA"))
	{
		cub->map.wall[3] = init_img(cub->mlx, map_split[1]);
		cub->map.ea++;
		cub->map.index++;
	}
	else if (!ft_strcmp(map_split[0], "C"))
	{
		check_colors(cub, map_split[1], 'C');
		cub->map.c++;
		cub->map.index++;
	}
	else if (!ft_strcmp(map_split[0], "F"))
	{
		check_colors(cub, map_split[1], 'F');
		cub->map.f++;
		cub->map.index++;
	}
}

void	check_valid_format(t_cub *cub)
{
	int		i;
	int		y;
	char	**map_split;

	i = 0;
	y = 0;
	while (cub->map.str[i])
	{
		map_split = ft_split(cub->map.str[i], ' ');
		y = 0;
		while (map_split[0][y])
		{
			if (map_split[0][y] == '\n')
				map_split[0][y] = '\0';
			y++;
		}
		parse_texture(cub, map_split);
		i++;
	}
	cub->map.index_spaces = check_new_index(cub);
	printf("index = %d\n", cub->map.index);
	if ((cub->map.index != 6 && !check_walls_first_line_char(cub)) || (cub->map.no != 1 || cub->map.so != 1 || cub->map.we != 1
			|| cub->map.ea != 1 || cub->map.c != 1 || cub->map.no != 1))
		error_msg("Error\nInvalid format :Missing textures or colors");
	printf("so = %d\n", cub->map.so);
	//if (cub->map.index == 6 )
			//error_msg("Error\nInvalid format :Missi");
	//if (check_path_texture(cub))
		//error_msg("Error\nInvalid path for textures"); //
}