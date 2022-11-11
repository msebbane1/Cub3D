/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:39 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/11 15:53:36 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	parse_texture_color(t_cub *cub, char **map_split)
{
	if (!ft_strcmp(map_split[0], "NO"))
		cub->map.wall[0] = init_img(cub->mlx, map_split[1]);
	if (!ft_strcmp(map_split[0], "SO"))
		cub->map.wall[1] = init_img(cub->mlx, map_split[1]);
	if (!ft_strcmp(map_split[0], "WE"))
		cub->map.wall[2] = init_img(cub->mlx, map_split[1]);
	if (!ft_strcmp(map_split[0], "EA"))
		cub->map.wall[3] = init_img(cub->mlx, map_split[1]);
	if (!ft_strcmp(map_split[0], "F"))
		printf("color\n");//check_color
	if (!ft_strcmp(map_split[0], "C"))
		printf("color\n");//check_color
	else
		return (1);
	return (0);
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

int	ft_char_texture2(char *line)
{
	int	i;

	i = 0;
	skip_spaces(line, &i);
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C' || line[i] == '\0')
		return (1);
	return (0);
}

int	skip_spaces(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t'
		|| line[*i] == '\n' || line[*i] == '\r'
		|| line[*i] == '\v' || line[*i] == '\f')
	{
		(*i)++;
		return (1);
	}
	return (0);
}

int	check_new_index(t_cub *cub)
{
	int		i;
	int		index;
	char	**map_split;

	i = 0;
	map_split = ft_split(cub->map.str[i], ' ');
	index = cub->map.index_spaces;
	while (cub->map.str[i])
	{
		if (ft_char_texture2(cub->map.str[i])
			&& parse_texture_color(cub, map_split))
			index++;
		i++;
	}
	return (index);
}

void	check_valid_format(t_cub *cub)
{
	int		i;
	char	**map_split;

	i = 0;
	map_split = ft_split(cub->map.str[i], ' ');
	while (cub->map.str[i])
	{
		if (ft_char_texture(cub->map.str[i])
			&& parse_texture_color(cub, map_split))
			cub->map.index++;
		i++;
	}
	//printf("map_split = %s\n", map_split[1]); // == PATH
	if (cub->map.index != 6)
		error_msg("Error\nInvalid format :Missing textures or colors");
	cub->map.index_spaces = check_new_index(cub);
}

/*
*Check que c'est bien un path apres le format (commence bien par un path ./)
*check que c'est bien une couleur (split les ,)
*Erreur quand je met la meme lettre a la 1ere ligne de ma map m'affiche l'erreur [pas la bonne erreur]  
*/