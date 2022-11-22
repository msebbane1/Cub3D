/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:39 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/22 14:13:05 by msebbane         ###   ########.fr       */
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

/* map_split[0] = SO map_split[1] = path ou couleur*/
void	parse_texture(t_cub *cub, char **map_split)
{
	printf("mapspli = %s\n", map_split[0]);
	if (!ft_strcmp(map_split[0], "NO"))
		cub->map.wall[0] = init_img(cub->mlx, map_split[1]);
	else if (!ft_strcmp(map_split[0], "SO"))
		cub->map.wall[1] = init_img(cub->mlx, map_split[1]);
	else if (!ft_strcmp(map_split[0], "WE"))
		cub->map.wall[2] = init_img(cub->mlx, map_split[1]);
	else if (!ft_strcmp(map_split[0], "EA"))
		cub->map.wall[3] = init_img(cub->mlx, map_split[1]);
	else if (!ft_strcmp(map_split[0], "C"))
		check_colors(cub, map_split[1], 'C');
	else if (!ft_strcmp(map_split[0], "F"))
		check_colors(cub, map_split[1], 'F');
}

int	ft_char_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C' || line[i] == '\0')
		return (1);
	return (0);
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
		if (ft_char_texture(cub->map.str[i]))
			cub->map.index++;
		parse_texture(cub, map_split);
		i++;
	}
	cub->map.index_spaces = check_new_index(cub);
	printf("index = %d\n", cub->map.index);
	if (cub->map.index != 6 && !check_walls_first_line_char(cub))
			error_msg("Error\nInvalid format :Missing textures or colors");
	//if (check_path_texture(cub))
		//error_msg("Error\nInvalid path for textures");
}

/*
*Check que c'est bien un path apres le format (commence bien par un path ./)
*check 
*Erreur quand je met la meme lettre a la 1ere ligne de ma map m'affiche l'erreur [pas la bonne erreur]  
*/