/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:39 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/22 18:01:59 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_path_texture(t_cub *cub)
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
}

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

int	parse_color(t_cub *cub, char **map_split)
{
	if (!ft_strcmp(map_split[0], "C"))
		check_colors(cub, map_split[1], 'C');
	else if (!ft_strcmp(map_split[0], "F"))
		check_colors(cub, map_split[1], 'F');
	else
		return (1);
	return (0);
}

void	parse_texture2(t_cub *cub, char **map_split)
{
	if (!ft_strcmp(map_split[0], "EA"))
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

void	parse_texture(t_cub *cub, char **map_split)
{
	printf("mapspli = %s\n", map_split[0]);
	if (!ft_strcmp(map_split[0], "NO"))
	{
		cub->map.wall[0] = init_img(cub->mlx, map_split[1]);
		//cub->no_path = ft_strdup(map_split[1]);? + free
		cub->map.no++;
		cub->map.index++;
	}
	else if (!ft_strcmp(map_split[0], "SO"))
	{
		cub->map.wall[1] = init_img(cub->mlx, map_split[1]);
		cub->map.so++;
		cub->map.index++;
	}
	else if (!ft_strcmp(map_split[0], "WE"))
	{
		cub->map.wall[2] = init_img(cub->mlx, map_split[1]);
		cub->map.we++;
		cub->map.index++;
	}
	parse_texture2(cub, map_split);
}

int	ft_skip_format(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\n' || line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C' || line[i] == '\0')
		return (1);
	return (0);
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
	if ((cub->map.index != 6 && !check_walls_first_line_char(cub))
		|| cub->map.no != 1 || cub->map.so != 1 || cub->map.we != 1
		|| cub->map.ea != 1 || cub->map.c != 1 || cub->map.no != 1)
		error_msg("Error\nInvalid format :Missing textures or colors");
	//if (check_path_texture(cub))
		//error_msg("Error\nInvalid path for textures");
}

/*
*Check que c'est bien un path apres le format (commence bien par un path ./)
*check 
*Erreur quand je met la meme lettre a la 1ere ligne de ma map m'affiche l'erreur [pas la bonne erreur]  
*/